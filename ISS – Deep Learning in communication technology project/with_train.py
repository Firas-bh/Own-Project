import tensorflow as tf
import os
import komm
# Bib zur Bearbeitung von Bildern (Keras, OpenCV)

import struct
from tensorflow import keras
import numpy as np
import matplotlib.pyplot as plt
from tensorflow.keras import layers
from tensorflow.keras.layers import Input, Dense, Conv2D, MaxPooling2D, BatchNormalization, Flatten, Reshape, Conv2DTranspose, LeakyReLU, Activation
from tensorflow import keras


np.random.seed(42)
tf.random.set_seed(42)

"""Dataset"""
dataset = tf.keras.datasets.mnist
(x_train, _), (x_test, _) = dataset.load_data()
x_train, x_test = x_train/255.0, x_test/255.0
#print(x_test[0])
def ecoder():
    inputs = Input(shape=(28, 28, 1))

    x = inputs

    x = layers.Conv2D(16, (3, 3), activation='relu', padding='same')(x)
    x = layers.MaxPooling2D((2, 2), padding='same')(x)
    x = layers.Conv2D(8, (3, 3), activation='relu', padding='same')(x)
    x = layers.MaxPooling2D((2, 2), padding='same')(x)
    x = layers.Conv2D(4, (3, 3), activation='relu', padding='same')(x)
    #x = layers.MaxPooling2D((2, 2), padding='same')(x)
    #x = layers.Conv2D(2, (3, 3), activation='relu', padding='same')(x)
    encoded = layers.MaxPooling2D((2, 2), padding='same')(x)
    print("das ist: ", x.shape)
    #print(encoded.shape)
    encoded = Flatten()(encoded)
    print(encoded.shape)
    return inputs, encoded


def ecodermodel(i):
    j = x_test
    encoder = ecoder()
    #inputs = Input(shape=(28, 28 , 1))
    encoder = keras.Model(encoder[0], encoder[1])
    f = encoder.predict(j)
    return f[i]

def dcoder():
    encoder = ecoder()
    inputs = layers.Reshape((4, 4, 4))(encoder[1])
    # x = layers.Conv2D(4, (3, 3), activation='relu', padding='same')(x)
    # x = layers.UpSampling2D((2, 2))(x)
    x = layers.Conv2D(4, (3, 3), activation='relu', padding='same')(inputs)
    x = layers.UpSampling2D((2, 2))(x)
    x = layers.Conv2D(8, (3, 3), activation='relu', padding='same')(x)
    x = layers.UpSampling2D((2, 2))(x)
    x = layers.Conv2D(16, (3, 3), activation='relu')(x)
    x = layers.UpSampling2D((2, 2))(x)
    decoded = layers.Conv2D(1, (3, 3), activation='sigmoid', padding='same')(x)
    print(decoded)
    return inputs

def decodermodel(mylist):
    decoder = dcoder()
    print(decoder.shape)
    decoder = keras.Model(mylist, decoder)
    print(decoder)


















##############################################################

def bin2float(b):
    ''' Convert binary string to a float.

    Attributes:
        :b: Binary string to transform.
    '''
    h = int(b, 2).to_bytes(8, byteorder="big")
    return struct.unpack('>d', h)[0]


def float2bin(f):
    ''' Convert float to 64-bit binary string.

    Attributes:
        :f: Float number to transform.
    '''
    [d] = struct.unpack(">Q", struct.pack(">d", f))
    return f'{d:064b}'





def imgtobitstream (imgname):
    # Bild vom Arbeitsverzeichnis öffnen
    img = np.array(ecodermodel(imgname))
    # Zusammenfassung der Bildeigenschaften
    #print(img.shape)    # Bild in numpy Array konvertieren
    #print(img)
    imgbytes = []
    for im in img:
        imgbytes += bytearray(struct.pack("f", im))
    imgbytesnp = np.asarray(imgbytes, dtype=np.uint8)
    print(imgbytesnp)
    bitstream = np.unpackbits(imgbytesnp)
    return bitstream

def pskmodulation (imgdata):
    pskmodulation = komm.PSKModulation(4)
    bitstopoints = pskmodulation.modulate((imgdata))
    print(bitstopoints)
    return bitstopoints

def awgnchannel (bitstopoints):
    # Signal to noise = 63.0, signal_power = 1.0 default
    awgn = komm.AWGNChannel(snr=63.0)
    signal = awgn(bitstopoints)
    print("Signal: " + str(bitstopoints))
    print("Verrauschtes Signal: " + str(signal))
    return signal

def pskdemodulation (signal):
    pskmodulation = komm.PSKModulation(4)
    pointstobits = pskmodulation.demodulate(signal)
    print("Empfangene Bitfolge: " + str(pointstobits))
    arr_1d_rest = np.packbits(pointstobits)
    print("... bitstream recompressed")
    # shape array
    cnt = 0
    arr = []
    vals = []
    for val in arr_1d_rest:
        arr += [val]
        cnt = cnt + 1
        if cnt == 4:
            vals += [struct.unpack("<f", bytearray(arr))]
            arr = []
            cnt = 0
    vals = np.array(vals)
    vals = vals.reshape(64)
    print(vals.shape)
    return vals

stream = imgtobitstream(0)
psk = pskmodulation(stream)
channel = awgnchannel(psk)
pskafterchannel = pskdemodulation(channel)
ask = decodermodel(pskafterchannel)
