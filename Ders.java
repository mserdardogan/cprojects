package cprojects;

class Kutu {
        int a, b, c;

        int alan() {
                return a * b * c;
        }

        public Kutu(int a, int b, int c) {
                this.a = a;
                this.b = b;
                this.c = c;
        }

}

class Ders {
        public static void main(String[] args) {
                Kutu kutu = new Kutu(5, 4, 3);
                System.out.println("Küpün alanı: " + kutu.alan());
        }
}