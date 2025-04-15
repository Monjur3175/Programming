
class Animal{
    void sound()
    {
        System.out.println("Animal makes a Sound");
    }
}
class dog extends Animal{
    @Override
    void sound()
    {
        System.out.println("Dog Barks!");
    }
}
public class methodoverriding {
    public static void main(String[] args) {
        Animal d=new dog();
        d.sound();
    }
}
