#include <stdio.h>
#include "spellbook.h"

int main() {
    Spellbook * lista = create_spellbook();
    Spell s;

    for(int i = 0; i < 1; i++) {
        printf("Insira um nome:\n");
        scanf(" %[^\n]s", s.name);
        printf("Insira o id:\n");
        scanf("%d", &s.id);
        printf("Insira o custo de mana:\n");
        scanf("%d", &s.mana_const);
        add_spell(lista, s.id, s.name, s.mana_const);
    }
    display_spellbook(lista);

    destroy_spellbook(lista);

    display_spellbook(lista);

}