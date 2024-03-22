package junit.com;

public class Revision extends State{

    public String opName;
    public String getStateInfo(){
        return opName;
    }

    public Revision(String opName){
        this.opName = opName;
    }
}
