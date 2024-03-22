package junit.com;

public class Revised extends State{

    public String revisedDate;
    public String getStateInfo(){
        return revisedDate;
    }

    public Revised(String revisedDate){
        this.revisedDate = revisedDate;
    }
}
