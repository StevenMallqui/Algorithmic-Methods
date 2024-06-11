Dijkstra(DigrafoValorado<Valor> const& g, int orig, Valor distancia_limite) 
        : origen(orig), dist(g.V(), INF), ulti(g.V()), pq(g.V()), limite(distancia_limite) {
        dist[origen] = 0;
        pq.push(origen, 0);
        while (!pq.empty()) {
            int v = pq.top().elem;
            if (dist[v] > limite) break; // Detener si la distancia mínima es mayor que el límite
            pq.pop();
            for (auto a : g.ady(v)) {
                relajar(a);
            }
        }
    }