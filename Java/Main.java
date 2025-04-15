interface Animal {
    void makeSound();
    void move();
}
interface Mammal extends Animal {
    void nurse();
}
class Dog implements Mammal {
    @Override
    public void makeSound() {
        System.out.println("Woof!");
    }

    @Override
    public void move() {
        System.out.println("Running!");
    }

    @Override
    public void nurse() {
        System.out.println("Nursing puppies.");
    }
}
class Cat implements Mammal {
    @Override
    public void makeSound() {
        System.out.println("Meow!");
    }

    @Override
    public void move() {
        System.out.println("Walking gracefully!");
    }

    @Override
    public void nurse() {
        System.out.println("Nursing kittens.");
    }
}
class Bird implements Animal {
    @Override
    public void makeSound() {
        System.out.println("Chirp!");
    }

    @Override
    public void move() {
        System.out.println("Flying!");
    }
}

// Main class to test the implementation
public class Main {
    public static void main(String[] args) {
        // Create instances of each class
        Mammal myDog = new Dog();
        Mammal myCat = new Cat();
        Animal myBird = new Bird();

        // Call methods on Dog
        System.out.println("Dog:");
        myDog.makeSound(); // Output: Woof!
        myDog.move(); // Output: Running!
        myDog.nurse(); // Output: Nursing puppies.

        // Call methods on Cat
        System.out.println("\nCat:");
        myCat.makeSound(); // Output: Meow!
        myCat.move(); // Output: Walking gracefully!
        myCat.nurse(); // Output: Nursing kittens.

        // Call methods on Bird
        System.out.println("\nBird:");
        myBird.makeSound(); // Output: Chirp!
        myBird.move(); // Output: Flying!
    }
}
