# ROOT

Path: /

## Descripció del directori:
En aquest directori es troba tota la informació del projecte

## Elements del directori:

### DOCS:
Conté tota la documentació del projecte: un diagrama de casos d'ús amb una descripció de cada cas d'ús, un diagrama estàtic complet del model de dades conceptual a la versió de disseny i una breu descripció de les propietats i mètodes de les classes utilitzades per cadascun. membre de l'equip per implementar la funcionalitat lliurada Descripció d'estructures de dades i algorismes.

### EXE:
Fitxers executables (.jars) per a totes les classes, que permeten provar la funcionalitat principal implementada. Cada tipus de classe té subdirectoris: prova, excepcions, funcions, tipus, i aquests subdirectoris segueixen l'estructura que determina el paquet.

### FONTS:
Codi per a classes de domini relacionades amb la funcionalitat principal implementada fins ara. També inclou proves JUnit. Tots els fitxers es troben en subdirectoris que segueixen l'estructura del paquet perquè el codi es pugui compilar directament.

## Executar el programa:
Cal anar al directori `/FONTS/subgrup-prop31.2` on es troba el codi del programa.

## Instruccions per executar
- `./gradlew jar`

		Compila totes les classes

- `java -jar build/libs/gradlepoc-1.0-SNAPSHOT.jar`

		Executa el codi del programa

- `./gradlew test`

		Executa tots els tests de totes les classes

- `./gradlew --tests TestNomClasse`
		
		Executa el test de la classe NomClasse

- `make jars`
		
		Compila totes les funcionalitats de l'aplicació per separat i les deixa a ./EXE/NomFuncionalitat/NomDriver.jar

- `java -jar ../../EXE/NomFuncionalitat/NomDriver.jar`

		Executa la funcionalitat concreta NomFuncionalitat de la classe NomDriver

- `make clean`
		
		Elimina els fitxers del directori ./EXE/out

- `make distclean`
		
		Elimina els fitxers jar de les carpetes de les seves respectives funcionalitats