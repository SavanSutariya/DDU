class Student{
    private int id,sem;
    private String name,department;
    private Result r;
    class Result{
        private int marks1,marks2,marks3;
        Result(int m1,int m2,int m3){
            marks1=m1;
            marks2=m2;
            marks3=m3;
        }
        public void display(){
            System.out.println("Marks1: "+marks1);
            System.out.println("Marks2: "+marks2);
            System.out.println("Marks3: "+marks3);
        }
    }
    Student(int i,String n,String d,int s,int m1,int m2,int m3){
        id=i;
        name=n;
        department=d;
        sem=s;
        r=new Result(m1,m2,m3);
    }
    public void display(){
        System.out.println("ID: "+id);
        System.out.println("Name: "+name);
        System.out.println("Department: "+department);
        System.out.println("Semester: "+sem);
        r.display();
    }

}