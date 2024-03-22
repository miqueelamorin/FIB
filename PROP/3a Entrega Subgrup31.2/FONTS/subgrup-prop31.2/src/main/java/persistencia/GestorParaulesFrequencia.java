package persistencia;

import com.google.gson.Gson;
import domini.ParaulesFrequencia;

import java.io.*;
import java.util.HashMap;
import java.util.Map;

/**
 * Classe GestorParaulesFrequencia que gestiona l'emmagatzematge i la càrrega de llistes de paraules amb freqüència utilitzant la llibreria Gson.
 */
public class GestorParaulesFrequencia {
    /**
     * Guarda les llistes de paraules amb freqüència proporcionades en format JSON en un fitxer especificat pel path.
     * @param llistaParaulesFrequencia Mapa que conté parells de noms de llistes i instàncies de ParaulesFrequencia.
     * @param path Path del fitxer on es guardarà la informació de les llistes de paraules amb freqüència.
     * @throws IOException Excepció que es llança en cas d'error d'entrada/sortida durant l'escriptura al fitxer.
     */
    public void guardarParaulesFrequencia(Map<String, ParaulesFrequencia> llistaParaulesFrequencia, String path) throws IOException {
        BufferedWriter writer = new BufferedWriter(new FileWriter(path));
        Gson gson = new Gson();
        for (Map.Entry<String, ParaulesFrequencia> paraulesFrequencia : llistaParaulesFrequencia.entrySet()) {
            String jsonParaulesFrequencia = gson.toJson(paraulesFrequencia.getValue());
            writer.write(jsonParaulesFrequencia + "\n");
        }
        writer.close();
    }

    /**
     * Carrega les llistes de paraules amb freqüència des d'un fitxer especificat pel path i les retorna com un mapa.
     * @param path Path del fitxer on es troba la informació de les llistes de paraules amb freqüència.
     * @return Mapa que conté parells de noms de llistes i instàncies de ParaulesFrequencia carregades.
     * @throws IOException Excepció que es llança en cas d'error d'entrada/sortida durant la lectura del fitxer.
     */
    public Map<String, ParaulesFrequencia> carregarParaulesFrequencia(String path) throws IOException {
        Map<String, ParaulesFrequencia> llistaParaulesFrequencia = new HashMap<>();
        BufferedReader reader = new BufferedReader(new FileReader(path));
        Gson gson = new Gson();
        String fila;
        while ((fila = reader.readLine()) != null) {
            ParaulesFrequencia paraulesFrequencia = gson.fromJson(fila, ParaulesFrequencia.class);
            llistaParaulesFrequencia.put(paraulesFrequencia.getNom(), paraulesFrequencia);
        }
        return llistaParaulesFrequencia;
    }
}
