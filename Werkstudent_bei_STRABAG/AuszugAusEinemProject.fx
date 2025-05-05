// Spinner aktivieren
Set(varspinner; true);;

// Sammlung leeren
Clear(st_gesamt);;
Clear(Berechnungen);;



Set(startTime; Now());;
// FCO-Daten vorfiltern (einmalig filtern, um Performance zu verbessern)

ClearCollect(jahrtesttt; Distinct(UenMerhErfiltereddd; Jahr));;

// Berechnungen vorbereiten (pro Jahr in der Gallery)
ClearCollect(
    year_sums;
    ForAll(
        jahrtesttt;
        {
            Jahr: Value;
            'KSt Gesamt': Sum(Filter(UenMerhErfiltereddd; Jahr = Value); KST);
            'GewSt Gesamt': Sum(Filter(UenMerhErfiltereddd; Jahr = Value); GewSt);
            'USt Gesamt': Sum(Filter(UenMerhErfiltereddd; Jahr = Value); USt);
            'LSt Gesamt': Sum(Filter(UenMerhErfiltereddd; Jahr = Value); LSt)
        }
    )
);;

// Berechnung von 'St_Gesamt' basierend auf den bereits berechneten Summen
ClearCollect(
    st_gesamt;
    ForAll(
        year_sums;
        {
            Jahr: Jahr;
            'KSt Gesamt': 'KSt Gesamt';
            'BG KSt Gesamt': 'KSt Gesamt' * 0,15;
            'GewSt Gesamt': 'GewSt Gesamt';
            'BG GewSt Gesamt': 'GewSt Gesamt' * 0,15*Varhebelsatz;
            'USt Gesamt': 'USt Gesamt';
            'LSt Gesamt': 'LSt Gesamt';
             St_Gesamt: 'KSt Gesamt' + 'GewSt Gesamt' + 'USt Gesamt' + 'LSt Gesamt';
            'BG St_Gesamt': ('KSt Gesamt' * 0,15) + ('GewSt Gesamt' * 0,15*Varhebelsatz) + 'USt Gesamt' + 'LSt Gesamt';
            'Gültig ab': DateValue(DateAdd(DateValue(DateAdd(Date(Value(Jahr);12;31); 1; TimeUnit.Days)); 15; TimeUnit.Months))
        }
    )
);;


ClearCollect(st_gesamt_withAllYear; Sort(st_gesamt; Jahr; SortOrder.Ascending));;

ClearCollect(
    st_gesamt_sorted;
    Sort(st_gesamt; Jahr; SortOrder.Ascending)
);;



ForAll(st_gesamt_sorted;
Remove(
    st_gesamt_sorted;
    LookUp(
        st_gesamt_sorted;
        IsBlank('KSt Gesamt') && 
        IsBlank('GewSt Gesamt') && 
        IsBlank('USt Gesamt') && 
        IsBlank('LSt Gesamt')
    )
)
);;



ForAll(st_gesamt_sorted;  //ohne 2023
Remove(
    st_gesamt_sorted;
    LookUp(
        st_gesamt_sorted;
        'Gültig ab'> DateValue(DatePicker1.SelectedDate)
    )
)
);;




Clear(Zinstable);;

ClearCollect(
    Zinstable;
    Sort('Beispiel_Zinssaetze-233a';ZinsatzAb; SortOrder.Ascending )
);;

Set(gesamtbetrag; Last(st_gesamt).St_Gesamt);;  // Beispiel: 5 Millionen Euro Last(UenMerhErfiltered).St_Gesamt
Set(EndBetrag; 0);; // Der Endbetrag, der berechnet wird

//Clear(GefilterteZinssätze);;
Clear(Berechnungen);;
// Berechnung der Zinsen
// Filtern und Sortieren der Zinssätze in eine neue Sammlung

Clear(GefilterteZinssätze_Copy);;




ForAll(
    st_gesamt_sorted;
    Collect(
        GefilterteZinssätze_Copy;
        ForAll(
            Filter(
                Zinstable;
                ZinsatzAb <= DateValue('Gültig ab') && 
                GueltigBis >= DateValue('Gültig ab') || 
                IsBlank(GueltigBis) && 'Gültig ab' <= DateValue(DatePicker1.SelectedDate) && ZinsatzAb <= DateValue(DatePicker1.SelectedDate)
            );
            // Füge das Jahr aus st_gesamt_sorted als neue Spalte hinzu
            {
                Jahr_filter: Jahr; // Hier wird das Jahr von der aktuellen Zeile in st_gesamt_sorted zugewiesen
                ZinsatzAb: DateValue(ThisRecord.ZinsatzAb);  // Die bestehenden Felder aus Zinstable
                Prozent: ThisRecord.Prozent;
                GueltigBis: DateValue(ThisRecord.GueltigBis)
            }
        )
    )
);;
	
 Filter(st_gesamt_sorted; LookUp(GefilterteZinssätze_Copy; ThisRecord.Jahr_filter = Jahr; Prozent));;



ForAll(
    st_gesamt_sorted;
    // Für jedes Jahr aus st_gesamt_sorted
    ForAll(
        Filter(GefilterteZinssätze_Copy; Jahr_filter = st_gesamt_sorted[@Jahr]); 
        // Für jedes Jahr und jeden Prozentsatz aus GefilterteZinssätze_Copy
        Collect(
            Berechnungen;
            {
                ZeitraumStart: Max(ZinsatzAb; DateValue('Gültig ab'));
                ZeitraumEnde: If(IsBlank(GueltigBis); DateValue(DatePicker1.SelectedDate); GueltigBis);
                Zinsperiode: DateDiff(Max(ZinsatzAb; DateValue('Gültig ab')); If(IsBlank(GueltigBis); DateValue(DatePicker1.SelectedDate); GueltigBis); TimeUnit.Days);
                
                // Berechnung der Zinsen unter Verwendung des aktuellen Prozentsatzes
                Zinsen: 
                ( 
                    'BG St_Gesamt' * 
                    Prozent * 
                    DateDiff(Max(ZinsatzAb; DateValue('Gültig ab')); If(IsBlank(GueltigBis); DateValue(DatePicker1.SelectedDate); GueltigBis); TimeUnit.Days)
                ) / 360;
                Jahr_test: Jahr;
                Prozent: Prozent
            }
        )
    )
);;

Set(
    EndBetrag;
    Sum(
        Berechnungen;
        Zinsen
    )
);;

 

Set(endTime; Now());;
Set(duration; DateDiff(startTime; endTime; TimeUnit.Seconds));;


// Spinner deaktivieren
Set(varspinner; false);;

Set(PrintScreen; true);;

