# PlaylistQT  for Spotify
##### Versão 1.0
PlaylistQT é um demo para criação de uma playlist com armazenamento local para o Spotify. Tem como finalidade principal somente demonstrar os recursos do Qt e como meta, acessar o Spotify.


# Problemas identificados

- Não é apresentada nenhuma mensagem indicativa em caso de falha na gravação ou leitura de qualquer arquivo (de configuração ou playlists)
- Não é apresentada nenhuma mensagem de erro através do programa em caso de falha na busca




#### Histórico de mudanças
###### Versão 1.0
- Inclusão do acesso a API do Spotfy

###### Versão 0.02

- Inclusão da comunicação entre a classe PlayListController e a MainWindow (SLOT e signal), fazendo com que a listview da MainWindow  seja atualizada conforme o conteudo da playlist mude. Comunicação somente implementada para demonstrar o uso de Signal e Slots.
- Melhora na formatação dos elementos visuais: agora os componentes se ajustam conforme as dimensões da janela são alteradas.
