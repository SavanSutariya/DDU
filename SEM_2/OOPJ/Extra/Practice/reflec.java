import java.lang.reflect.*;

class Hello{
    public int i;
    private float b;
    Hello(){
        System.out.println("Hello");
    }
    Hello(int i){
        this.i = i;
    }
    public void bye(int i){
        System.out.println("bye");
    }
    public void ok(){
        System.out.println("bys");
    }
}
class reflec{
    public static void main(String []args) throws Exception{
        Hello h = new Hello();
        Class cc = Class.forName("Hello");
        Class c = h.getClass();
        System.out.println(c.getName());
        System.out.println(c.getDeclaredMethods());
        // System.out.println(c.getDeclaredFields());
        Field [] fields = c.getDeclaredFields();
        for(Field f: fields){
            System.out.print(f.getType()+" ");
            System.out.print(f.getModifiers());
            System.out.println(f.getName());
        }
        Constructor [] constructors = c.getConstructors();
        for(Constructor con: constructors){
            System.out.println(con.getName());
        }
        Method [] methods = c.getDeclaredMethods();
        for(Method m: methods){
            System.out.println(m.getName());
            System.out.println(m.getReturnType());
            // Show parameters
            Class [] params = m.getParameterTypes();
            for(Class p: params){
                System.out.println(p.getName());
            }
        }
        // System.out.println(c.getMethods());
    }
}