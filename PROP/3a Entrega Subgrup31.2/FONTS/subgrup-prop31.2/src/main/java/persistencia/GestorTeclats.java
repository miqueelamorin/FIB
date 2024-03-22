package persistencia;

import com.google.gson.Gson;
import com.google.gson.GsonBuilder;
import domini.CreadorTeclat;
import domini.Teclat;

import java.io.*;
import java.util.HashMap;
import java.util.Map;

/**
 * Classe GestorTeclats que gestiona l'emmagatzematge i la càrrega de teclats utilitzant la llibreria Gson.
 */
public class GestorTeclats {
    /**
     * Guarda els teclats proporcionats en format JSON en un fitxer especificat pel path.
     * @param teclats Mapa que conté parells de noms de teclats i instàncies de Teclat.
     * @param path Path del fitxer on es guardarà la informació dels teclats.
     * @throws IOException Excepció que es llança en cas d'error d'entrada/sortida durant l'escriptura al fitxer.
     */
    public void guardarTeclats(Map<String, Teclat> teclats, String path) throws IOException {
        BufferedWriter writer = new BufferedWriter(new FileWriter(path));

        Gson gson = new GsonBuilder()
                .registerTypeAdapter(CreadorTeclat.class, new CreadorTeclatAdapter())
                .create();

        for (Map.Entry<String, Teclat> teclat : teclats.entrySet()) {
            String jsonTeclat = gson.toJson(teclat.getValue());
            writer.write(jsonTeclat + "\n");
        }
        writer.close();
    }

    /**
     * Carrega els teclats des d'un fitxer especificat pel path i els retorna com un mapa.
     * @param path Path del fitxer on es troba la informació dels teclats.
     * @return Mapa que conté parells de noms de teclats i instàncies de Teclat carregades.
     * @throws IOException Excepció que es llança en cas d'error d'entrada/sortida durant la lectura del fitxer.
     */
    public Map<String, Teclat> carregarTeclats(String path) throws IOException {
        Map<String, Teclat> teclats = new HashMap<>();
        BufferedReader reader = new BufferedReader(new FileReader(path));

        Gson gson = new GsonBuilder()
                .registerTypeAdapter(CreadorTeclat.class, new CreadorTeclatAdapter())
                .create();

        String fila;
        while ((fila = reader.readLine()) != null) {
            Teclat teclat = gson.fromJson(fila, Teclat.class);
            teclats.put(teclat.getNom(), teclat);
        }
        return teclats;
    }
}
