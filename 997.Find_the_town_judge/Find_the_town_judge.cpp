class Solution {
public:
    //funçao procura juiz 
    // n =  numeros de pessoas na cidade 
    // vetor de relaçoes de confiaças das pessoas da cidade 
    int findJudge(int n, vector<vector<int>>& relacoes) {
    // Vetores para contar a confiança recebida e emitida
    vector<int> confiaEM(n + 1, 0);
    vector<int> confiaRecebida(n + 1, 0);

    //pecorrendo as relaçoes 
    for (const auto& t : relacoes) {
        //variavel para armazenar a pessoa que confia em alguem
        int pessoaAconfia = t[0];
        //variavel para armazenar a pessoa que a outra pessoa confia 
        int emPessoaB = t[1];
        ///incrementa no vetor 
        confiaEM[pessoaAconfia]++;
        confiaRecebida[emPessoaB]++;
    }

    // Verificando se existe um juiz
    for (int i = 1; i <= n; ++i) {
        if (confiaEM[i] == 0 && confiaRecebida[i] == n - 1) {
            return i;
        }
    }

    return -1;
        
    }
};