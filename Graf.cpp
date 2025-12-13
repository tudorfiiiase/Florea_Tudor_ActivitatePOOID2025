#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

// Clasa template Graf
template <typename T>
class Graf {
private:
    unordered_map<T, std::unordered_set<T>> adiacenta; // Liste de adiacență
    bool orientat; // Indică dacă graful este orientat

public:
    // Constructor
    explicit Graf(bool orientat = true) : orientat(orientat) {}

    // Adaugă un nod în graf
    void adaugaNod(const T& nod) {
        adiacenta[nod]; // Creează o intrare pentru nod
    }

    // Adaugă o muchie în graf
    void adaugaMuchie(const T& sursa, const T& destinatie) {
        adiacenta[sursa].insert(destinatie);
        if (!orientat) {
            adiacenta[destinatie].insert(sursa); // Adaugă muchie și în sens invers pentru graf neorientat
        }
    }

    // BFS (Breadth-First Search)
    void BFS(const T& start) const {
        unordered_set<T> vizitat;
        queue<T> coada;

        coada.push(start);
        vizitat.insert(start);

        cout << "BFS: ";
        while (!coada.empty()) {
            T nodCurent = coada.front();
            coada.pop();
            cout << nodCurent << " ";

            for (const auto& vecin : adiacenta.at(nodCurent)) {
                if (vizitat.find(vecin) == vizitat.end()) {
                    coada.push(vecin);
                    vizitat.insert(vecin);
                }
            }
        }
        cout << endl;
    }

    // DFS (Depth-First Search) - Iterativ
    void DFS(const T& start) const {
        unordered_set<T> vizitat;
        stack<T> stiva;

        stiva.push(start);

        cout << "DFS: ";
        while (!stiva.empty()) {
            T nodCurent = stiva.top();
            stiva.pop();

            if (vizitat.find(nodCurent) == vizitat.end()) {
                cout << nodCurent << " ";
                vizitat.insert(nodCurent);

                for (const auto& vecin : adiacenta.at(nodCurent)) {
                    if (vizitat.find(vecin) == vizitat.end()) {
                        stiva.push(vecin);
                    }
                }
            }
        }
        std::cout << std::endl;
    }

    // Afișare grafic
    void afiseaza() const {
        cout << "Grafic:\n";
        for (const auto& nod : adiacenta) {
            cout << nod.first << ": ";
            for (const auto& vecin : nod.second) {
                cout << vecin << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    // Creăm un graf neorientat
    Graf<int> graf(false);

    // Adăugăm noduri și muchii
    graf.adaugaNod(1);
    graf.adaugaNod(2);
    graf.adaugaNod(3);
    graf.adaugaNod(4);

    graf.adaugaMuchie(1, 2);
    graf.adaugaMuchie(1, 3);
    graf.adaugaMuchie(2, 4);
    graf.adaugaMuchie(3, 4);

    // Afișăm graficul
    graf.afiseaza();

    // Executăm BFS și DFS
    graf.BFS(1);
    graf.DFS(1);

    return 0;
}
