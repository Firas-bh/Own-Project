# Own-Project
University projects as well as excerpts from the current working student position
## ISS – Deep Learning in communication technology project

+ Entwicklung eines Encoder-Decoder-Modells

+ Kompression und Dekompression von Bildern aus dem MNIST-Datensatz mithilfe neuronaler Netze

+ Übertragung der Daten unter Verwendung der QPSK-Modulation

## **📡 Bildübertragung mit Autoencoder & PSK-Modulation**
Dieses Projekt simuliert eine robuste Bildübertragung über verrauschte Kanäle durch die Kombination von Deep Learning (Autoencoder) und klassischer Signalverarbeitung (PSK). Die Implementierung erfolgte in drei Phasen:

**🔄 Projektphasen**

### Phase 1: Einarbeitung & Grundlagen
+ Literaturrecherche zu PSK-Modulation und AWGN-Kanälen

+ Einrichtung der Python-Umgebung mit Anaconda (inkl. TensorFlow, NumPy, komm)

+ Entwicklung einer Basisimplementierung ohne ML

### Phase 2: Klassische Signalverarbeitung
+ Manuelle Feature-Extraktion:

  - Direkte Umwandlung von Bildpixeln in Bitstreams

+ PSK-Modulation (QPSK):

  - Phasenkodierung der Rohdaten

+ Limitationen:

  - Keine Anpassung an Bildinhalte

+ Empfindlich gegen Rauschen

### Phase 3: Autoencoder-Ansatz (Deep Learning)
+ Encoder:

 - Komprimiert Bilder in einen 64-D latenten Raum

+ PSK-Übertragung:

 - Moduliert nur die komprimierte Repräsentation

+ Decoder:

  - Rekonstruiert Bilder aus verrauschten Daten

+ Vorteile:

  ✅ Geringere Bandbreitennutzung

  ✅ Rauschtoleranz durch Feature-Learning

  ✅ End-to-End trainierbar

### Phase 4: Abschluss
+ Präsentation der Ergebnisse

+ Vergleich beider Ansätze (Bitfehlerrate, Rekonstruktionsqualität)
## 🛠 Technologien
Python 3.9 | TensorFlow/Keras | NumPy | komm | Matplotlib
