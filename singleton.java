public class Person {
    private static final Person INSTANCE_EAGER = new Person(); // Eager instantiation
    private static volatile Person INSTANCE_LAZY; // Lazy instantiation

    private int autoid;
    private String username;
    private String password;
    private String gender;

    private Person() {
        // Private constructor to prevent direct instantiation
    }

    public static Person getInstanceEager() {
        return INSTANCE_EAGER;
    }

    public static Person getInstanceLazy() {
        if (INSTANCE_LAZY == null) {
            synchronized (Person.class) {
                if (INSTANCE_LAZY == null) {
                    INSTANCE_LAZY = new Person();
                }
            }
        }
        return INSTANCE_LAZY;
    }

    @Override
    public String toString() {
        return "Person{" +
                "autoid=" + autoid +
                ", username='" + username + '\'' +
                ", password='" + password + '\'' +
                ", gender='" + gender + '\'' +
                '}';
    }

    public static void main(String[] args) {
        Person p1 = Person.getInstanceEager();
        System.out.println("p1 " + p1);

        Person p2 = Person.getInstanceEager();
        System.out.println("p2 " + p2);

        System.out.println("p1 hashcode: " + p1.hashCode());
        System.out.println("p2 hashcode: " + p2.hashCode());

        Person p3 = Person.getInstanceLazy();
        System.out.println("p3 " + p3);

        System.out.println("p1 hashcode: " + p1.hashCode());
        System.out.println("p3 hashcode: " + p3.hashCode());
    }
}
