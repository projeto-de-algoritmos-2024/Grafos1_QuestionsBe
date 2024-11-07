class Solution{
    public: 
    //funçao para encontrar o itinerario 
    vector<string> findItinerary(vector<vector<string>>& passagens){
        //map q armazena em forma de tabela
        map<string ,vector<string>> tabelaPassagens;
        //vetor que armazena resultado final 
        vector<string> resultado;

        //preencher tabela 
        for(const auto& passagem : passagens){
           ///tirando cada valor do vetor passagens
           const string& partida = passagem[0];
           const string& chegada = passagem[1];

           //preencher a tabela 
           tabelaPassagens[partida].push_back(chegada);

        }

        // mantendo a ordem alfabetica reversa
        for (auto& entry : tabelaPassagens) {
            sort(entry.second.rbegin(), entry.second.rend());
        }

        dfs("JFK",tabelaPassagens,resultado);

        reverse(resultado.begin(), resultado.end());

        return resultado;
    }

    private:
    //funçao de busca em profundidade começando por 'JFK'
    void dfs(const string& sFixa, map<string,vector<string>>& tabelaPassagens, vector<string>& resultado){
        //apontando para o destino 
        vector<string>& destinos = tabelaPassagens[sFixa];

        //pecorrendo os destinos 
        while (!destinos.empty()) {
            //extraindo os destinos 
            string proxDestino = destinos.back();
            destinos.pop_back();
        
            // Chama recursivamente para o próximo destino
            dfs(proxDestino, tabelaPassagens, resultado);
        }

        //adicionando após correr todos os destinos 
        resultado.push_back(sFixa);        
    }
       

};