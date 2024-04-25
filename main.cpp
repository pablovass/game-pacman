#include <allegro5/allegro5.h>
#include <allegro5/allegro_image.h>
#include <iostream> // Agregar esta línea

int main() {
    // Inicializar Allegro
    al_init();
    al_init_image_addon();

    // Cargar la imagen desde el archivo
    ALLEGRO_BITMAP* image = al_load_bitmap("image.jpg");

    // Verificar si la imagen se cargó correctamente
    if(!image) {
        std::cerr << "Error al cargar la imagen." << std::endl;
        return -1;
    }

    // Crear una ventana
    ALLEGRO_DISPLAY* display = al_create_display(al_get_bitmap_width(image), al_get_bitmap_height(image));
    if(!display) {
        std::cerr << "Error al crear la ventana." << std::endl;
        al_destroy_bitmap(image);
        return -1;
    }

    // Dibujar la imagen en la ventana
    al_draw_bitmap(image, 0, 0, 0);

    // Actualizar la ventana
    al_flip_display();

    // Esperar a que se presione una tecla
    al_rest(5.0); // Esperar 5 segundos

    // Liberar recursos
    al_destroy_display(display);
    al_destroy_bitmap(image);

    return 0;
}
