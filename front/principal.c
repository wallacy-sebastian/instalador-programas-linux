#include <gtk/gtk.h>
#include "componentes.h"
#include "principal.h"

static GtkWidget *criarContainerPrincipalEntradas() {
    GtkWidget *container_entradas = NULL;
    GtkWidget *nome_programa = NULL, *descricao = NULL, *tipo = NULL,
        *categoria = NULL, *caminho_exec = NULL, *caminho_icon = NULL,
        *variaveis_ambiente = NULL;

    container_entradas = gtk_grid_new();
	gtk_grid_set_row_spacing(GTK_GRID(container_entradas), 33);
    gtk_grid_set_column_spacing(GTK_GRID(container_entradas), 30);
    gtk_grid_set_column_homogeneous(GTK_GRID(container_entradas), TRUE);
	gtk_widget_set_halign(container_entradas, GTK_ALIGN_FILL);
	gtk_widget_set_valign(container_entradas, GTK_ALIGN_START);

    nome_programa = criarCampoEntradaDescricao(
        "Nome do programa",
        criarCampoEntrada("", "ex: Touhou 18"));
    descricao = criarCampoEntradaDescricao(
        "Descrição curta",
        criarCampoEntrada("", "ex: Touhou 18 - Unconnected Marketeers"));
    tipo = criarCampoEntradaDescricao(
        "Tipo",
        criarCampoEntrada("", "ex: Application"));
    categoria = criarCampoEntradaDescricao(
        "Categoria",
        criarCampoEntrada("", "ex: Game"));
    caminho_exec = criarCampoEntradaDescricao(
        "Caminho do arquivo de execução",
        criarCampoEntrada("", "ex: ~/Touhou 18/th18.exe"));
    caminho_icon = criarCampoEntradaDescricao(
        "Caminho do ícone do programa",
        criarCampoEntrada("", "ex: ~/Imagens/touhou-18-icon.png"));
    variaveis_ambiente = criarCampoEntradaDescricao(
        "Digite as variáveis de ambiente, se houver, da seguinte forma:\n[VARIAVEL]=[VALOR]; [VARIAVEL2]=[VALOR2]",
        criarCampoEntrada("", "ex: WINEPREFIX=~/.touhou-18; WINEARCH=win64"));

	gtk_grid_attach(GTK_GRID(container_entradas), nome_programa, 0, 0, 1, 1);
	gtk_grid_attach(GTK_GRID(container_entradas), descricao, 1, 0, 1, 1);
    gtk_grid_attach(GTK_GRID(container_entradas), tipo, 0, 1, 1, 1);
    gtk_grid_attach(GTK_GRID(container_entradas), categoria, 1, 1, 1, 1);
    gtk_grid_attach(GTK_GRID(container_entradas), caminho_exec, 0, 2, 1, 1);
    gtk_grid_attach(GTK_GRID(container_entradas), caminho_icon, 1, 2, 1, 1);
    gtk_grid_attach(GTK_GRID(container_entradas), variaveis_ambiente, 0, 3, 2, 1);

    return container_entradas;
}

GtkWidget *criarContainerPrincipal() {
    GtkWidget *container = NULL, *container_entradas = NULL;
    GtkWidget *instalar = NULL, *fechar = NULL, *ajuda = NULL;
    GtkWidget *ajuda_icon = NULL;

    container = gtk_grid_new();
    gtk_widget_set_margin_end(container, 45);
    gtk_widget_set_margin_bottom(container, 15);

    container_entradas = criarContainerPrincipalEntradas();
    gtk_widget_set_hexpand(container_entradas, TRUE);

    ajuda = gtk_button_new();
    ajuda_icon = gtk_image_new_from_file("assets/ajuda-icon.png");
    gtk_button_set_child(GTK_BUTTON(ajuda), ajuda_icon);

    instalar = gtk_button_new_with_label("Instalar");
    gtk_widget_set_margin_top(instalar, 55);
    fechar = gtk_button_new_with_label("Fechar");
    gtk_widget_set_margin_top(fechar, 55);

    gtk_grid_attach(GTK_GRID(container), ajuda, 0, 0, 1, 1);
    gtk_grid_attach(GTK_GRID(container), container_entradas, 1, 2, 40, 22);
    gtk_grid_attach(GTK_GRID(container), instalar, 11, 25, 9, 1);
    gtk_grid_attach(GTK_GRID(container), fechar, 22, 25, 9, 1);

    return container;
}