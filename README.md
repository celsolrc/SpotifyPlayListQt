# PlaylistQT  for Spotify
##### Versão 0.02
PlaylistQT é um demo para criação de uma playlist com armazenamento local para o Spotify. Tem como finalidade principal somente demonstrar os recursos do Qt e como meta, acessar o Spotify.

Nesta primera versão, o acesso ao Spotify não está funcional e ainda existem alguns detalhes a serem melhorados



# Problemas identificados

  - Falha de segurança: a senha de acesso ao Spotify está sendo armazenada localmente e sem criptografia.
  - Não é apresentada nenhuma mensagem indicativa em caso de falha na gravação ou leitura de qualquer arquivo (de configuração ou playlists)


# Implementações futuras
- Não está acessando a API do Spotify. Com isso, as "músicas" listadas são textos fixos dentro do código
- Pelo mesmo motivo acima, não executa nenhuma música
- Habilitar/Desabilitar opções do menu conforme estado de conexão com o Spotify. No momento todos as opções estão habilitadas.



#### Histórico de mudanças
###### Versão 0.02

- Inclusão da comunicação entre a classe PlayListController e a MainWindow (SLOT e signal), fazendo com que a listview da MainWindow  seja atualizada conforme o conteudo da playlist mude. Comunicação somente implementada para demonstrar o uso de Signal e Slots.
- Melhora na formatação dos elementos visuais: agora os componentes se ajustam conforme as dimensões da janela são alteradas.
