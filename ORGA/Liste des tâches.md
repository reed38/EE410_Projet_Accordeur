
### Phase 1 (avec capteur arduino)

- [ ] lister datasheets/specs pour capteur et carte arduino
- [ ] Tester le fonctionnement du capteur avec oscillo, en prendre un autre si CPT
- [ ] rechercher le domaine/intervalle de fonctionnement recherché
	- [ ] regarder domaine de fréquence/ intensité sonnore pour plusieurs instruments
		- [ ] guitare
		- [ ] piano
		- [ ] saxophone
		- [ ] trompette
- [ ] Tester le capteur en connexion serial avec l'arduino 
	- [ ] afficher dans terminal valeurs reçues
	- [ ] tenter de faire un graphe amplitude/temps
	- [ ] regarder erreur statique
	- [ ] regarder seuil de saturation
	
- [ ] Copier un algo de fft ou de de Goertzel, voir si la carte est capable de gérer le calcul à une vitesse acceptable
- [ ] choisir arduino/stm32 en fonction du résultat
- [ ] Implementer algo basique de reconnaissance des fréquences, sortie port serial
- [ ] lister les composants à commander
	- [ ] choisir le capteur, regarder montages analogiques possibles pour amplification/filtrage signal
	- [ ] tester afficheur, regarder si besoin d'en commander un autre
	- [ ] tester boutons poussoirs, regarder si besoin d'en commander un autre
- [ ] rédiger le rapport intermédiaire
### Phase 2
- [ ] Intégrer le capteur
	- [ ] faire cahier des charges specs micro
	- [ ] choisir montage/valeurs resistance
	- [ ] simulation ltspice?
	- [ ] assemblage/test
- [ ] tester avec prog comparer perf avec capteur arduino
- [ ] implémenter prog pour déterminer la note/ accord en fonction du spectre/freq principale
- [ ] implémenter afficheur
- [ ] implémenter plusieurs mode
- [ ] implémenter boutton pour changer de mode

on verra

