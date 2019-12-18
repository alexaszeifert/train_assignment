# train_assignment

Assignment for our Programming 2 course

## Description:
 
Vasúton szállítunk termékeket. A termékeket be lehet rakodni vasúti kocsikba. A kocsik csatlakoztathatóak menetrend szerinti járatokhoz. A járatok oda-vissza járnak egy útvonalon, ami több állomást érinthet. A menetrend tartalmazza azt is, hogy melyik állomást mikor érinti a vonat, ezek kerek órákban vannak megadva. Feltehető, hogy nincs két állomás ugyanabban az órában. A program számára a vasúti menetrend, a kocsik adatai, és a vonatokra csatlakoztatható kocsik száma az egyik input.

A kocsik adatai: szöveges azonosító, kapacitás (hány csomag fér bele), kezdetben melyik állomáson van. Kezdetben minden kocsi üres.

A menetrend adatai: [ állomásnév, eltelt idő ] sorozat, ami az oda-vissza utat felöleli. Minden vonat kezdetben az első állomásán van, akkor is, ha az első eltelt idő értéke nem nulla, ez az ismétlések közötti várakozási időt jelenti.

A termékeknek forráshelyük és célhelyük van, amik állomásnevekkel azonosítottak. A termékekről lehet tudni, hogy hány csomag mennyiségben vannak jelen kezdetben a forráshelyen.

A programnak meg kell adnia azt az akciótervet, aminek a hatására az összes áru leszállítása megtörténik úgy, hogy a legutolsó leszállítás időpontja minél korábban legyen. Ha nem lehetséges valaminek a kiszállítása, akkor ezt jeleznie kell a programnak, megnevezve az ignorált árukat, és a lehetséges árukra kell vonatkoznia a leghamarabb leszállított utolsó árunak.

### Akcióterv elemek:

* Adott órában kocsi töltése áruval (csak nem csatlakoztatott kocsit szabad tölteni)
* Adott órában kocsi csatlakoztatása vonathoz (nem lehet ugyanazon órában tölteni és csatlakoztatni
* Adott órában kocsi leválasztása kocsiról (egy órában egy kocsi leválasztása és csatlakoztatása átcsatolást jelent egy másik vonatra, szabad lecsatolni és pakolni ugyanazon órában)
* Adott órában kocsi kipakolása (csak nem csatlakoztatott kocsit szabad kipakolni)

### Example:

**Menetrend:** Egy A-B-C útvonal egy lehetséges vonatának menetrendje lehet ilyen:

> V1 2
> A 1 
> B 2 
> C 4
> B 6
> A 7

Ennek a jelentése az, hogy a V1 nevű, kettő kocsit elbíró vonat a kezdeti állapot után egy órával indul a vonat, bejárja az állomásokat, és utána ismétli a bejárást úgy, hogy az indulás pillanata a 8-as órában lesz, mert 7-re beért, de újrakezdve a menetrendjét egy óra várakozással kezd az első bejegyzés miatt.

**Kocsik:**

> a 10 A
> b 15 B

**Áruk:**

> cucc1 A C 35
> cucc2 B C 15

**kimeneti akcióterv:**

> 0 pakol a cucc1 10

*// van egy óránk pakolni, mert csak 1-kor indul a vonat*

> 0 pakol b cucc2 15
> 1 csatol a V1
> 2 csatol b V1
> 4 lecsatol a V1
> 4 lecsatol b V1
> 5 kipakol a cucc1 10
> 5 kipakol b cucc2 15

*// ebben a pillanatban már a cucc2 teljesen megérkezett, a cucc1-ből még van 25 csomag A-ban, de elment a vonat, ezért meg kell várni a csatolással mire újra itt jár, mert az üres kocsikat vissza kell vinni hogy feltölthessük*

> 11 csatol a V1

*// 11 = 7+4, ilyenkor van másodszor C-ben V1 vonat*

> 11 csatol b V1
> 14 lecsatol a V1
> 14 lecsatol b V1
> 14 pakol a cucc1 10
> 14 pakol b cucc1 15
> 15 csatol a V1
> 15 csatol b V1
> 18 lecsatol a V1
> 18 lecsatol b V1
> 19 kipakol a cucc1 10
> 19 kipakol b cucc1 15

**Notes:**

Nem kötelező kipakolásnál mindent kipakolni. Amit nem pakolunk ki explicit, az benne marad.

Kocsi bármely állomáson bármennyit állhat bármilyen állapotban

Az itt látható példa nem formátum előírás, lehet saját formátumot használni, és bemutatón leírás alapján bemeneti fájlokat gyártani.

A program által megadott adatok ellenőrzése kedvéért a programot lehessen debug módban futtatva akár óránként teljes állapotleírást adni arról, hogy mi hol van az akcióterv végrehajtása során.

Ezen dokumentum utoljára dec. 2-án változott, a példa javításával (hiányzó lecsatolások 14. órában) és a szabályoknál a magyarázatban explicitebben kijelentjük, hogy szabad lecsatolni és pakolni bármely irányban ugyanabban az órában, csak csatolás nem történhet ugyanabban az órában...
