#include <gtk/gtk.h>
#include "aplicacao.h"

static GtkApplication *aplicacao;

gboolean registrarVariaveis(GtkApplication *app) {
    if(app != NULL) {
		aplicacao = app;
        
        return TRUE;
    }

	return FALSE;
}

GtkApplication *retornaAplicacao() {
    return aplicacao;
}

GtkWidget *criarJanela(gint largura, gint altura, char *titulo) {
    GtkWidget *janela;

	janela = gtk_application_window_new(aplicacao);
	gtk_window_set_title(GTK_WINDOW(janela), titulo);
	gtk_window_set_default_size(GTK_WINDOW(janela), largura, altura);
	gtk_application_add_window(aplicacao, GTK_WINDOW(janela));

	return janela;
}
