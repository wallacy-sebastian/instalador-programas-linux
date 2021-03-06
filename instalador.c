#include <gtk/gtk.h>
#include "front/aplicacao.h"
#include "front/principal.h"

/**
 * Estrutura para receber os argumentos adicionais e repassá-las através das funções do GTK
 */

struct _args {
    int argc;
    char **argv;
};

typedef struct _args args;

/**
 * Prepara a aplicação antes de executá-la
 */

void ativar(GtkApplication *app, gpointer user_data) {
    GtkWidget *janela = NULL;
    GtkWidget *principal = NULL;
    args *argumentos = NULL;
    bool check = FALSE;

    check = registrarVariaveis(app);

    if(check == FALSE) {
        printf("Erro ao iniciar a aplicação.");
        exit(0);
    }

    argumentos = (args *) user_data;
    janela = criarJanela(770, 535, "Instalador de programas");
    principal = criarContainerPrincipal();
    gtk_window_set_child(GTK_WINDOW(janela), principal);

    gtk_widget_show(janela);
}

/**
 * Principal
 */

int main(int argc, char *argv[]) {
    GtkApplication *aplicacao = NULL;
	int status = 0;
    args *argumentos = NULL;

    argumentos = (args *) calloc(1, sizeof(args));

    argumentos->argc = argc;
    argumentos->argv = argv;

	aplicacao = gtk_application_new("instalador.linux", G_APPLICATION_FLAGS_NONE);
	g_signal_connect(aplicacao, "activate", G_CALLBACK(ativar), (void *) argumentos);
	status = g_application_run(G_APPLICATION(aplicacao), argumentos->argc, argumentos->argv);
	g_object_unref(aplicacao);

	return status;
}