#if !defined(APLICACAO_H)
#define APLICACAO_H

/* Armazena as principais variáveis da aplicação */
gboolean registrarVariaveis(GtkApplication *app);
/* Retorna o ponteiro para a aplicação */
GtkApplication *retornaAplicacao();

/* Cria uma janela */
GtkWidget *criarJanela(gint largura, gint altura, char *titulo);

#endif // APLICACAO_H