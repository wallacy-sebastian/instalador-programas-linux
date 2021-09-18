#if !defined(COMPONENTES_H)
#define COMPONENTES_H

/* Cria um campo com entrada de texto */
GtkWidget *criarCampoEntrada(gchar *textoInicial, gchar *placeholder);
/* Adiciona uma label ao campo com entrada de texto */
GtkWidget *criarCampoEntradaDescricao(gchar *descricao, GtkWidget *campo);

#endif // COMPONENTES_H