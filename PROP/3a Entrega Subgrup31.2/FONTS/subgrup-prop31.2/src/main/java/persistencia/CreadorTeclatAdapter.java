package persistencia;

import com.google.gson.*;
import domini.BranchAndBound;
import domini.CreadorTeclat;
import domini.GeneticAlgorithm;

import java.lang.reflect.Type;

/**
 * Classe CreadorTeclatAdapter encarregada de indicar a la llibreria GSON com ha de serialitzar i deserialitzar la interficie CreadorTeclat a format json.
 */
public class CreadorTeclatAdapter implements JsonSerializer<CreadorTeclat>, JsonDeserializer<CreadorTeclat> {
    /**
     * Deserialitza les dades en format JSON a un objecte que implementa la interfície CreadorTeclat.
     * @param json Les dades en format json que volem convertir a objecte
     * @param typeOfT El tipus de l'objecte a deserialitzar
     * @param context Contexte de deserialització proporcionat pel sistema.
     * @return Retorna un objecte que implementa la interficie CreadorTeclat.
     * @throws JsonParseException Excepció que es llança en cas que el format no sigui el correcte.
     */
    @Override
    public CreadorTeclat deserialize(JsonElement json, Type typeOfT, JsonDeserializationContext context) throws JsonParseException {
        JsonObject creadorTeclatObject = json.getAsJsonObject();
        JsonElement algoritme = creadorTeclatObject.get("algoritme");
        if (algoritme.getAsString().equals(BranchAndBound.class.getName()))
            return context.deserialize(creadorTeclatObject, BranchAndBound.class);
        else if (algoritme.getAsString().equals(GeneticAlgorithm.class.getName()))
            return context.deserialize(creadorTeclatObject, GeneticAlgorithm.class);
        else
            return null;
    }

    /**
     * Serialitza un objecte que implementa la interfície CreadorTeclat a un element JSON.
     * @param src Objecte de una classe que implementa la interfície CreadorTeclat.
     * @param typeOfSrc Tipus de l'objecte a ser serialitzat
     * @param context Contexte de serialització proporcionat pel sistema
     * @return Retorna un element JSON que representa l'objecte CreadorTeclat amb la informació de l'algoritme.
     */
    @Override
    public JsonElement serialize(CreadorTeclat src, Type typeOfSrc, JsonSerializationContext context) {
        JsonObject creadorTeclatJson = new JsonObject();
        creadorTeclatJson.addProperty("algoritme", src.getClass().getName());
        return creadorTeclatJson;
    }
}
