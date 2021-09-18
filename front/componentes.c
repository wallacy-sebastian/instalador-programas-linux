#include <gtk/gtk.h>
#include "componentes.h"

GtkWidget *criarCampoEntrada(gchar *textoInicial, gchar *placeholder) {
    GtkWidget *campo = NULL;
    GtkEntryBuffer *buffer = NULL;

    campo = gtk_entry_new();
    buffer = gtk_entry_buffer_new(textoInicial, -1);

    gtk_entry_set_buffer(GTK_ENTRY(campo), buffer);
    gtk_entry_set_placeholder_text(GTK_ENTRY(campo), placeholder);

    return campo;
}

GtkWidget *criarCampoEntradaDescricao(gchar *descricao, GtkWidget *campo) {
    GtkWidget *grid = NULL;
    GtkWidget *label = NULL;

    grid = gtk_grid_new();
    gtk_grid_set_row_spacing(GTK_GRID(grid), 10);

    label = gtk_label_new(descricao);

    gtk_grid_attach(GTK_GRID(grid), label, 0, 0, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), campo, 0, 1, 1, 1);

    gtk_grid_set_column_homogeneous(GTK_GRID(grid), TRUE);

    return grid;
}
