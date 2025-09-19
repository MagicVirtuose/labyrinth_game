
char** generate_labyrinth();

char* get_frontiers(char** labyrinth, int x, int y);

void connect_to_neighbor(char** labyrinth, int x, int y);

void save_labyrinth(char** labyrinth);