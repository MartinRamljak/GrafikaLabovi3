# **GrafikaProjektTemplate**

Premake5 je jednostavan alat za automatsko konfiguriranje razvojnog okruženja, a skripta je napisana u Lua skriptnom jeziku. Ovaj alat omogućuje nam konfiguriranje našeg okruženja (vrsta projekta, platforma, mapa binarnih datoteka, povezivanje s libovima itd.) unutar premake5.lua skripte.
Nakon konfiguracije, možemo pokrenuti premake5 s argumentom za željeno okruženje, a alat će generirati traženo okruženje. Općenito, ovakav alat omogućuje nam generiranje okruženja za naš projekt na različitim operacijskim sustavima s različitim libovima, a također i za različita razvojna okruženja (ne nužno Visual Studio). [Pogledajte dokumentaciju za premake](https://premake.github.io/docs/Using-Premake).
U praksi se koriste i drugi, kompleksniji alati za automatizaciju postavljanja, testiranje, izgradnju, instalaciju itd., kao što su CMake, SCons...

#### **NAPOMENA:** Za sada sam konfigurirao Premake samo za Visual Studio '17, '19 i '22, i to na Windowsima.

### **Struktura** **projekta**

Projekt *GrafikaLabovi_ImePrezime* nalazi se u istoimenom direktoriju i sastoji se od dva direktorija, res i src. U direktoriju res nalaze se modeli (OBJ datoteke), shaderi i teksture, svi organizirani u svojim direktorijima. U direktoriju src nalaze se kodovi, također organizirani po direktorijima, osim *main.cpp* i *glad.c*. U direktoriju  *vendor* nalaze se alati koji nisu naši, a koristit ćemo ih.

### **Pokretanje** **na** **WINDOWSIMA**
#### 1. Klonirajte ili preuzmite ovaj repozitorij. 
#### 2. U premake5.lua prominite linije 1., 7. i 8. u ime kako želite. 
#### 3. Ako ste promijenili  ime, **obavezno** promijenite ime direktorija *GrafikaLabovi_ImePrezime* u skladu s time.
#### 4. Otvorite batch skriptu *GenerateProject.bat* u tekstualnom editoru. Ovisno o verziji Visual Studija promijenite argument na *vs2017*, *vs2019*, ili *vs2022*.
#### 5. Sada pokrenite istu batch skriptu te će vam se generirat vs solution. 
#### 6. Otvorite Visual Studio solution, i u Solution Exploreru odaberite *Show All Files*, kako biste vidjeli sve datoteke i stvarne direktorije projekta. [Vidi sliku](https://i.stack.imgur.com/NmkhK.png).
#### **NAPOMENA:**  Ovo neće raditi ako u putanji ili imenu imate znakove č, ć, đ, š, ž itd.

### **Za** **ostale**
Za one koji su konfigurirali na macOS-u ili su konfigurirali Visual Studio sami, nastavite raditi u tom okruženju (ili, ako želite, konfigurirajte novo okruženje za ovu vježbu). Sve što trebate učiniti je kopirati sve datoteke iz src u direktorij projekta (obratite pažnju da vam main.cpp ne prepiše glavni dio i da su sve .cpp, .c, .h i .hpp datoteke uključene u projekt). Također kopirajte sve iz direktorija res u svoj projekt. Općenito, svi resursni datoteke trebali bi biti isključeni iz projekta, osim ako imate problema s .obj datotekama koje su uključene, u tom slučaju ih isključite. Sada organizirajte svoj projekt kako želite, ali svakako ćete morati promijeniti putanje (path) u kodu i prilagoditi ih vašim. Ja sam to postavio u Premake skripti.

#### Na primjeru:

```cpp
#include "Window.h"
#include "Renderer.h"
#include "Model.h"
#include "Shader.h"
#include "Texture.h"

#include "glm/glm.hpp"
```
 #### promijeniti (ako imate src folder, ovo je **primjer**) u: 
 ```cpp
#include "src/Window/Window.h"
#include "src/Renderer/Renderer.h"
#include "src/Model/Model.h"
#include "src/Shader/Shader.h"
#include "src/Texture/Texture.h"

#include "src/vendor/glm/glm.hpp"
```

#### za resurse nisam kratio path u premaku. Root patha vam je folder projekta.


### **GLSL** **ekstenzija**
Za shadere, koji će biti u zasebnim datotekama, ako ne koristite ekstenziju za prepoznavanje GLSL koda, onda nije bitna ekstenzija shader datoteke(može biti obična .txt datoteka), bitno je da je u tekstualnom obliku i da se može čitati. Ovi shaderi su vrlo jednostavni, i ako napravite pogrešku u sintaksi, konzola aplikacije će vam vratiti grešku u sintaksi i pokazati mjesto greške. Dakle, ekstenzija vam neće trebati.

Ja koristim [ovu verziju](https://marketplace.visualstudio.com/items?itemName=DanielScherzer.GLSL2022) ekstenzije za prepoznavanje GLSL-a u vs2019. Ekstenzije u vs-u instaliraju se [na ovaj način](https://learn.microsoft.com/en-us/visualstudio/ide/finding-and-using-visual-studio-extensions?view=vs-2022). Da bi ova ekstenzija (mislim da i ostale) prepoznala GLSL kod, shader mora imati ekstenziju *.glsl*.  Možete koristiti i neki drugi uređivač (npr. VS Code) i tamo pronaći ekstenziju.

### Ostalo
#### Ove upute sigurno sadrže pravopisne i gramatičke pogreške (ako želi netko ispraviti, neka napravi pull request). 
#### Za vježbu, sav C++ kod pišete u mainu (ako radite po templatu), a za svaki zadatak stvorite novi set shadera (za svaki zadatak npr. zad3Vertex.glsl i zad3Fragment.glsl ili smislite bolje nazive).
#### Također ovo je moja abstrakcija OpenGL-a, i nisan puno potrošia vremena, tako da... 
#### Preko metoda Shader klase (pogledaj Shader.h) postavljate vrijednosti uniformi.
#### Također, upute nisu baš najbolje napisane, pa mi se slobodno javite.