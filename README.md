
# Lista com Redimensionamento Dinâmico

O presente projeto consiste na implementação de uma lista ordenada com redimensionamento dinâmico em C++. O código possui funções para inserção de elementos em ordem crescente, exclusão de elementos, redimensionamento dinâmico e operações básicas como exibir a lista, verificar seu tamanho e reinicializá-la.

## Estrutura de Dados

O código usa uma estrutura de dados lista (do tipo LISTA) que possui: O ponteiro 'A' para o o vetor de registros (do tipo REGISTRO), onde cada registro contém uma chave (um número inteiro); o número atual de elementos na lista 'nroElem'; a capacidade total alocada para a lista (em termos de registros) 'capacidade'.

## Funções Implementadas

inicializarLista(LISTA* l): Inicializa a lista, aloca memória para a lista com uma capacidade inicial de 50 registros e define o número de elementos como 0.

exibirLista(LISTA* l): Exibe os elementos da lista, mostrando as chaves de cada registro.

tamanho(LISTA* l): Retorna o número de elementos na lista.

tamanhoEmBytes(LISTA* l): Retorna o tamanho da lista em bytes, considerando a estrutura da lista e a memória alocada para os registros.

buscaSequencial(LISTA* l, TIPOCHAVE ch): Realiza uma busca sequencial na lista, procurando uma chave específica. Se encontrar, retorna a posição do elemento; caso contrário, retorna ERRO (definido como -1).

resize(LISTA* l, int novaCapacidade): Redimensiona a lista para uma nova capacidade. Se a lista atinge o número máximo de registros, sua capacidade é aumentada, e seu tamanho, dobrado; se o número de registros for 25% do tamanho total da lista, ela é reduzida pela metade, sendo a capacidade mínima 50.

inserirElemListaOrd(LISTA* l, REGISTRO reg): Insere um novo registro na lista de forma ordenada (ordem crescente das chaves). Se necessário, redimensiona a lista para garantir que tenha capacidade suficiente.

excluirElemLista(LISTA* l, TIPOCHAVE ch): Exclui um elemento da lista com a chave especificada. Após a exclusão, a lista é reorganizada para manter a ordem. Se a quantidade de elementos for inferior a um quarto da capacidade e a capacidade for maior que 50, a lista será redimensionada para reduzir seu tamanho.

reinicializarLista(LISTA* l): Reinicializa a lista, definindo o número de elementos como 0.

## Fluxo do Programa no main

O código implementa um menu simples para interagir com o usuário:

### Inserção de Elementos:

O programa solicita ao usuário que insira elementos na lista. O valor -1 indica que o usuário deseja parar de inserir.
Para cada inserção, o valor é armazenado em um registro e inserido na lista de forma ordenada.
A lista é exibida após cada inserção, junto com o número de elementos e o tamanho em bytes da lista.

### Exclusão de Elementos:

O programa solicita ao usuário que insira um valor para excluir da lista. O valor -1 indica que o usuário deseja parar de excluir.
Para cada exclusão, o valor é removido da lista (se encontrado), e a lista é reexibida após cada operação, juntamente com o número de elementos e o tamanho em bytes da lista.

### Reinicialização da Lista:

Após a inserção e exclusão de elementos, o programa permite ao usuário reinicializar a lista, o que remove todos os elementos e a exibe novamente.

## Conclusão

O programa implementa com sucesso uma lista dinâmica seguindo os requerimentos específicados: dobrar seu tamanho quando o número máximo de registros é alcançado e reduzir seu tamanho pela metade quando o número de registros é inferior a 25% do tamanho da lista.