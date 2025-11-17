typedef struct {
    int id;
    char name [50];
    int mana_const;
} Spell;

typedef struct No {
    Spell dado;
    struct No * prox;
} No;

typedef struct {
    No * inicio;
} Spellbook;

Spellbook* create_spellbook();
void add_spell(Spellbook * book, int id, const char* name, int mana_cost);
void display_spellbook(Spellbook* book);
void destroy_spellbook(Spellbook* book); 