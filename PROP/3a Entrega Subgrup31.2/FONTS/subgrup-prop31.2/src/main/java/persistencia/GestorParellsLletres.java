package persistencia;

import com.google.gson.Gson;
import domini.Pair;
import domini.ParellsLletres;

import java.io.*;
import java.util.HashMap;
import java.util.Map;

/**
 * Classe GestorParellsLletres que gestiona l'emmagatzematge i la càrrega de parells de lletres utilitzant la llibreria Gson.
 */
public class GestorParellsLletres {
    /**
     * Guarda els parells de lletres proporcionats en format JSON en un fitxer especificat pel path.
     * @param llistaParellsLletres Mapa que conté parells de claus i instàncies de ParellsLletres.
     * @param path Path del fitxer on es guardarà la informació dels parells de lletres.
     * @throws IOException Excepció que es llança en cas d'error d'entrada/sortida durant l'escriptura al fitxer.
     */
    public void guardarParellsLletres(Map<Pair<String, String>, ParellsLletres> llistaParellsLletres, String path) throws IOException {
        BufferedWriter writer = new BufferedWriter(new FileWriter(path));
        Gson gson = new Gson();
        for (Map.Entry<Pair<String, String>, ParellsLletres> parellsLletres : llistaParellsLletres.entrySet()) {
            String jsonParellsLletres = gson.toJson(parellsLletres.getValue());
            writer.write(jsonParellsLletres + "\n");
        }
        writer.close();
    }

    /**
     * Carrega els parells de lletres des d'un fitxer especificat pel path i els retorna com un mapa.
     * @param path Path del fitxer on es troba la informació dels parells de lletres.
     * @return Mapa que conté parells de claus i instàncies de ParellsLletres carregades.
     * @throws IOException Excepció que es llança en cas d'error d'entrada/sortida durant la lectura del fitxer.
     */
    public Map<Pair<String,String>, ParellsLletres> carregarParellsLletres(String path) throws IOException {
        Map<Pair<String,String>, ParellsLletres> llistaParellsLletres = new HashMap<>();
        BufferedReader reader = new BufferedReader(new FileReader(path));
        Gson gson = new Gson();
        String fila;
        while ((fila = reader.readLine()) != null) {
            ParellsLletres parellsLletres = gson.fromJson(fila, ParellsLletres.class);
            Pair<String, String> clau = new Pair<>(
                    parellsLletres.getAlfabet().getNom(),
                    parellsLletres.getParaulesFreq().getNom());
            llistaParellsLletres.put(clau, parellsLletres);
        }
        return llistaParellsLletres;
    }
}
