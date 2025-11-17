#include "combate.h"

int calcular_ataque_total(int dano_base, int bonus) {
    return dano_base+bonus;
}

int aplicar_dano(int vida, int dano) {
    return vida - dano;
}