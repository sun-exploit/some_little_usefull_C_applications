# Mode d'emploi

**hash_table est une application console, qui est prévue pour fonctionner dans un terminal sous Linux seulement** (pour l'instant).

Tout est contenu dans l'archive table_de_hachage_ericb.tar.gz

Pour l'utiliser


## Téléchargement de l'archive

Pour télécharger tout ce qui concerne le C : 

git clone https://framagit.org/ericb/some_little_usefull_C_applications

Si vous ne souhaitez télécharger QUE la table de hashage, il suffit de ne télécharger que l'archive [table_de_hachage_ericb.tar.gz](https://framagit.org/ericb/some_little_usefull_C_applications/-/blob/master/table_de_hachage/table_de_hachage_ericb.tar.gz)

Avec votre navigateur, télécharger cette archive dans un répertoire donné, dont vous connaissez le chemin.


## Décompression

Ouvrir un terminal, et se placer dans le répertoire :

````
 cd /chemin/qui_contient_l'archive
````

La commande à entrer dans le termminal est :
````
tar zxvf table_de_hachage_ericb.tar.gz
````

## Création des binaires exécutables 

Toujours dans le même terminal, taper :

````
cd table_de_hashage
make
````


## Tester

````
cd build
./hash_table
````

## Comment aider ?

**Merci de remonter les bugs, et les suggestions d'améliorations !!**

Si vous avez besoin d'une licence plus permissive, il est prévu de mettre tout le code sous licence MIT d'ici quelques temps.


**Eric Bachard**
Le 21 juillet 2020


Remarque :
L'archive table_de_hachage_2020_07_21.tar.gz n'a été testée fonctionnelle que sous Linux, mais elle devrait pouvoir être très facilement adaptée à Mac OS X.