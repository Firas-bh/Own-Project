import numpy as np
import komm
# Bib zur Bearbeitung von Bildern (Keras, OpenCV)
from PIL import Image
from numpy import asarray


"""
Das Modul wandelt ein Bild in Bitstream um
"""

def imgtobitstream (imgname):
    # Bild vom Arbeitsverzeichnis öffnen
    img = Image.open(imgname)
    img.show()
    # Zusammenfassung der Bildeigenschaften
    print("Format: " + str(img.format))
    print("Groesse: " + str(img.size))
    print("Modus: " + str(img.mode))
    # Bild in numpy Array konvertieren
    data = asarray(img)
    # Groesse und Gestalt eines Arrays als Integer-Tupel
    arrayshape = asarray(data.shape)
    # Linearisierung von Arrays (reshape,flatten, ravel)
    # reshape aendert die Daten nicht
    array1dim = asarray(data.reshape(data.size))
    print("Arrayshape: " + str(arrayshape) + "\nPixelarray: " + str(data) + "\n1dimArray: " + str(array1dim))
    # Shape am Ende von 1dim-Array anhängen
    imgdata = np.append(array1dim, arrayshape)
    print("imgdata: " + str(imgdata) + "\nSize: " + str(imgdata.size))
    return imgdata

"""
Das Modul moduliert den Bitstream mittels PSK-Modulation
"""
def pskmodulation (imgdata):
    # unpackbits erwartet den Typen unsigned integer 1 byte
    bitstream = imgdata.astype('uint8')
    # array als Bits darstellen
    bits = np.unpackbits(bitstream)
    print("Versendete Bitfolge: " + str(bits))
    # PSK-Modulation definieren M = 4, ohne Phasenoffset, Amplitude = 1
    pskmodulation = komm.PSKModulation(4)
    bitstopoints = pskmodulation.modulate((bits))
    return bitstopoints

"""
Das Modul modelliert den AWGNChannel
"""

def awgnchannel (bitstopoints):
    # Signal to noise = 63.0, signal_power = 1.0 default
    awgn = komm.AWGNChannel(snr=63.0)
    signal = awgn(bitstopoints)
    print("Signal: " + str(bitstopoints))
    print("Verrauschtes Signal: " + str(signal))
    return signal

"""
Das Modul demoduliert den empfangenen Bitstream mittels PSK-Modulation
"""

def pskdemodulation (signal):
    pskmodulation = komm.PSKModulation(4)
    pointstobits = pskmodulation.demodulate(signal)
    print("Empfangene Bitfolge: " + str(pointstobits))
    return pointstobits

"""
Das Modul erzeugt aus dem Bitstream wieder ein Bild
"""

def bitstreamtoimg (pointstobits):
    # Bitfolge wieder in Pixelarray umwandeln
    data = np.packbits(pointstobits)
    dimension = asarray(data[-3:])
    data = np.delete(data,np.s_[-3:],0)
    print("Data: " + str(data) + "\nDimension: " + str(dimension))
    # Array in die originale Dimension reshapen
    orginialdata = data.reshape(dimension)
    print("Data: " + str(orginialdata))
    # Array in Bild
    img = Image.fromarray(orginialdata, 'RGB')
    img.show()


stream = imgtobitstream("Dom.jpg")
psk = pskmodulation(stream)
channel = awgnchannel(psk)
pskafterchannel = pskdemodulation(channel)
img = bitstreamtoimg(pskafterchannel)
