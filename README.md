
# Secured

Troisième projet du module CPE (Programmation élémentaire en C). Ce projet a pour but de faire du hachage de données avec un protocole de hashing (ici FNV-1A). 
## Documentation

Si vous souhaitez modifier le projet : 

Allez dans le dossier [src](https://github.com/EpitechPromo2028/B-CPE-110-LIL-1-1-secured-mathis.bukowski/tree/main/src), dans celui-ci vous avez :
    
- `commands` qui permet de gérer toutes les  interactions au niveau des commandes de la hashtable.
- `hashtable` qui permet de gérer les interactions de création ou de suppression d'une hashtable.
- `utils` qui permet de gérer toutes les fonctions requises au bout déroulement des 2 dossiers précédent.

N'oubliez pas de modifier le `hashtable.h` dans `include` pour ajouter des valeurs à la stucture ou des fonctions dans le reste du fichier.
Pour ajouter des fichiers dans la compilation de la librairie. N'oubliez pas de modifier la variable `SRC` : 
``` makefile
    SRC = src/utils/hash_func.c\
		src/utils/my_strlen.c\
		src/utils/my_put_nbr.c\
		src/utils/my_putchar.c\
		src/utils/my_putstr.c\
		src/utils/my_strcmp.c\
		src/utils/my_strdup.c\
		src/utils/mini_printf.c\
		src/hashtable/add_hashtable.c\
		src/hashtable/delete_hashtable.c\
		src/commands/ht_dump.c\
		src/commands/ht_search.c\
		src/commands/ht_insert.c\
		src/commands/ht_delete.c\
		src/utils/my_strcpy.c\
```


## Déploiement en local

Pour lancer le projet sans modification :

```bash
  git clone git@github.com:EpitechPromo2028/B-CPE-110-LIL-1-1-secured-mathis.bukowski.git
```

Une fois le repertoire cloné, vous avez juste à compiler le projet en faisant : 
``` bash
make all
```
Faire un fichier main avec les commandes dont vous avez besoin (ht_insert, ht_delete, ht_dump, ht_search)
Sans oublier de créer la table et de la supprimer (new_hashtable & delete_hashtable).

``` c
#include "../include/hashtable.h"
#include <stdio.h>

int main(void)
{
    hashtable_t *ht = new_hashtable(&hash , 4);

    ht_insert(ht, "Vision", "./Documents/Tournament/Modules/Vision");
    ht_insert(ht, "Kratos", "./Trash/Hollidays_pics/.secret_folder/kratos.ai");
    ht_insert(ht, "<3", "+33 6 31 45 61 23 71");
    ht_dump(ht);
    delete_hashtable(ht);
    return 0;
}
```

Ensuite faites : 
``` bash
gcc -g main.c -L./ -lhashtable -o a.out
```

Et exécuter le fichier `a.out`
```bash
./a.out
```
## Interactions Utilisateur

- Vous pouvez modifier votre fonction de hashing étant donné que pour chaque table, la commande prend un pointeur sur fonction en paramètre, vous permettant ainsi de modifier votre fonction et d'utiliser différents protocoles sur différentes tables.

