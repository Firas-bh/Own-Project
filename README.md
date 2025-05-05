# Own-Project
Universitätsprojekte sowie Auszüge aus der aktuellen Werkstudentenstelle.

Folgende Projekte sind:

+ [ISS – Deep Learning in communication technology project](#ISS---Deep-Learning-in-communication-technology-project)

+ [Werkstudent bei STRABAG](#Werkstudent-bei-STRABAG)


## ISS - Deep Learning in communication technology project

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

**[Python Skript von Phase 2](/ISS%20–%20Deep%20Learning%20in%20communication%20technology%20project/main.py)**

+ Manuelle Feature-Extraktion:

  - Direkte Umwandlung von Bildpixeln in Bitstreams

+ PSK-Modulation (QPSK):

  - Phasenkodierung der Rohdaten

+ Limitationen:

  - Keine Anpassung an Bildinhalte

+ Empfindlich gegen Rauschen

### Phase 3: Autoencoder-Ansatz (Deep Learning)

**[Python Skript von Phase 3](/ISS%20–%20Deep%20Learning%20in%20communication%20technology%20project/with_train.py)**

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

**[Python Skript von Phase 2](/ISS%20–%20Deep%20Learning%20in%20communication%20technology%20project/Presentation/Final_KI-ISS%20.pptx)**

+ Präsentation der Ergebnisse


+ Vergleich beider Ansätze (Bitfehlerrate, Rekonstruktionsqualität)
## 🛠 Technologien
Python 3.9 | TensorFlow/Keras | NumPy | komm | Matplotlib


## Werkstudent bei STRABAG

Finance Calculation Tool (PowerApps)
Hinweis: Dies ist eine anonymisierte Code-Demo. Alle firmenspezifischen Daten und Logiken wurden entfernt oder abstrahiert.

###🔒 Datenschutzhinweis
Aufgrund interner Compliance-Richtlinien enthält dieses Repository nur:

+ Generische Code-Ausschnitte

+ Anonymisierte Funktionsbeschreibungen

+ Keine echten Geschäftslogiken oder Datenstrukturen

### 📌 Funktionen
- Berechnung von Körperschaft-/Gewerbesteuer
- Dynamische Zinsberechnung (§233a)
- Fälligkeitsdatum-Logik

### ⚙️ Technische Details
| Komponente       | Beschreibung                |
|------------------|----------------------------|
| **Sprache**      | Power Fx                   |
| **Datenquellen** | SharePoint Lists           |
| **Key-Logik**    |[sehe hier](/Werkstudent_bei_STRABAG/AuszugAusEinemProject.fx)|
