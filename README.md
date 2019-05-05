# PlaylistQT  for Spotify

PlaylistQT é um demo para criação de uma playlist com armazenamento local para o Spotify. Tem como finalidade principal somente demonstrar os recursos do Qt e como meta, acessar o Spotify.

Nesta primera etapa o acesso ao Spotify não está completo e ainda existem alguns detalhes a serem melhorados

# Problemas identificados

  - Falha de segurança: a senha de acesso ao Spotify está sendo armazenada localmente e sem criptografia.
  - Não é apresentada nenhuma mensagem indicativa em caso de falha na gravação ou leitura de qualquer arquivo (de configuração ou playlists)


# Implementações futuras
- Não está acessando a API do Spotify. Com isso, as "musicas" listadas são textos fixos dentro do código
- Pelo mesmo motivo acima, não executa nenhuma música
- Habilitar/Desabilitar opções do menu conforme estado de conexão com o Spotify. No momento todos as opções estão habilitadas.

# Melhorias futuras
- Uso de SIGNAL e SLOTS para melhor independencia e segurança no código
- Melhorar a montagem e formatação dos elementos visuais para que as dimensões dos componentes seja ajustada conforme as dimensões da janela forem alteradas.