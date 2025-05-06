# Own-Project
Universitätsprojekte sowie Auszüge aus der aktuellen Werkstudentenstelle.

Folgende Projekte sind:

+ [ISS – Deep Learning in communication technology project](#ISS---Deep-Learning-in-communication-technology-project)

+ [Werkstudent bei STRABAG](#Werkstudent-bei-STRABAG)

+ [Praktikum Informatik 1](#Praktikum-Informatik-1)


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

### 🔒 Datenschutzhinweis
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


## Praktikum Informatik 1

[sehe hier](/PT-1_Informatik)

### C++ Programmierpraktikum - Algorithmen und Datenstrukturen
**📚 Praktikumsziele**

Dieses Praktikum vermittelt grundlegende Konzepte der Programmierung in C++ mit Fokus auf:

+ Sprachunabhängige Problemlösungen in C++ umsetzen

+ Qualitätsmerkmale von Algorithmen analysieren (Genauigkeit, Effizienz)

+ Moderne C++-Techniken wie Templates und Operatorenüberladung anwenden

+ Vergleichende Betrachtung von Lösungsansätzen

**🛠 Versuchsübersicht**
| Versuch | Thema                          | Schwerpunkte                                                                 |
|---------|--------------------------------|------------------------------------------------------------------------------|
| 1       | Eclipse-Umgebung               | Erstes C++-Programm, Entwicklungsumgebung einrichten                         |
| 2       | Datenstrukturen und Operationen | Grunddatentypen, Arrays, Structs, grundlegende Operationen                   |
| 3       | Ablauf- und Kontrollstrukturen  | Verzweigungen, Schleifen, Funktionsaufrufe                                   |
| 4       | Einführung in Klassen           | OOP-Grundlagen, Kapselung, Methoden                                          |
| 5       | Dynamische Datenstrukturen      | Pointer, Linked Lists, Speichermanagement, Doxygen-Dokumentation             |
| 6       | Standard Template Library (STL) | Container (vector, map), Algorithmen, Iteratoren                             |
| 7       | Objektorientierte Techniken     | Polymorphie, Operator Overloading, Friend-Klassen                            |
| 8       | Vererbung und abstrakte Typen   | Abstrakte Klassen, Interfaces, Mehrfachvererbung                             |

**🛠 Technischer Stack**

| Komponente               | Technologie/Optionen                      |
|--------------------------|------------------------------------------|
| **Programmiersprache**   | C++17/20                                 |
| **Entwicklungsumgebung** | Eclipse CDT                              |
| **Build-System**         | CMake/Make                               |
| **Dokumentation**        | Doxygen                                  |

