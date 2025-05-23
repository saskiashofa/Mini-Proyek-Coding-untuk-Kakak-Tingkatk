#include<stdio.h>
#include<string.h>

    char diary[100][500];   // Variabel untuk menyimpan isi diary dengan max diary 100 dan max 500 karakter
    char pw[15];            // Variabel untuk menyimpan password yang dimasukkan user 
    int jumlah = 0;         // Variabel untuk menyimpan jumlah diary yang ditulis
    int mood[100];          // Variabel untuk menyimpan mood dari tiap diary yang di tulis

// Fungsi untuk mengecek password agar hanya user yang tahu password yang bisa masuk
void cekPw(){
    do{
    printf("Masukin password dulu ya = "); // Meminta user memasukkan password
    scanf("%s", pw);    // Membaca input password
    // Mengecek apakah password yang dimasukkan tidak sama dengan "diaryku"
    if (strcmp(pw, "diaryku")!= 0) {
        printf("Password yang kamu masukin salah nih, yuk coba lagi!\n"); } // Pesan ditampilkan jika salah
    else
        printf("Yeayy, berhasil masukk!\n"); // Pesan ditampilkan jika benar
    } while (strcmp(pw, "diaryku") != 0); // Melakukan perulangan sampai password yang benar dimasukkan
}

// Fungsi untuk menulis diary 
void tulisDiary(){
    printf("Silahkan isi diary ini, tuliskan keluh kesah mu dihari ini!\n");
    scanf(" %[^\n]", diary[jumlah]); // Untuk membaca diary yang ditulis user, %[^\n] digunakan untuk membaca satu baris full dan simpan di diary ke-jumlah

    int pilMood; // Variabel untuk menyimpan pilihan mood user
    do{
        printf("\nMood kamu hari ini sedang... \n"); // Menampilkan menu pilihan mood
        printf("1. Senang nih!\n2. Lagi sedih:(\n3. Biasa aja sihh:'\n4. Badmooddd -_-\n");
        printf("Kamu lagi di mood yang mana? "); 
        scanf("%d", &pilMood); // Membaca input pilihan mood dari user

        if (pilMood < 1 || pilMood > 4) { // Jika pilihan tidak valid (kurang dari 1 atau lebih dari 4)
            printf("Pilihan tidak ada. Silakan pilih lagi.\n"); } // Pesan ditampilkan jika salah
    } while (pilMood < 1 || pilMood > 4); // Melakukan perulangan sampai pilihan mood yang benar dimasukkan

    // Mengecek mood sesuai pilihan user dan menampilkan pesan
    if (pilMood == 1) {
        printf("Aku ikut senang kalau kamu senang! Semoga hari-hari mu senang terus yaa <3\n");
    } else if (pilMood == 2) {
        printf("Sooo sad:( Aku ikut sedih sama hari mu, tapi gapapa aku tetap ada disini nemenin kamu :)\n");
    } else if (pilMood == 3) {
        printf("Ohh biasa aja ya.. Okeyy semoga besok hari mu lebih cerah dari hari ini yaa! :D\n");
    } else if (pilMood == 4) {
        printf("TENANGGG... Tarik nafas dan hembuskan, hari ini pasti berat banget semoga besok hari kamu bagus ya! :]\n");
    }
    mood[jumlah] = pilMood; // Menyimpan mood user ke array mood
    jumlah++; // Menambah jumlah diary yang tersimpan
}

// Fungsi untuk mencari dan menampilkan diary berdasarkan mood
void cariDiary(){
    if (jumlah == 0) { // Mengecek apakah ada riwayat diary yg ditulis
        printf("Belum ada diary yang ditulis\n"); // Menampilkan pesan jika tidak ada diary
        return; } // Keluar dari fungsi

    int pil; // Variabel untuk menyimpan pilihan mood untuk dicari
    int ketemu = 0; // Variabel untuk menandai jika ada diary yang cocok

    printf("\nKamu mau cari diary pas kamu lagi mood apa?\n"); // Menampilkan menu pilihan mood
    printf("1. Senang nih!\n2. Lagi sedih:(\n3. Biasa aja sihh\n4. Badmooddd -_-\n");
    printf("Masukkan pilihan mood kamu = ");    
    scanf("%d", &pil); // Membaca input pilihan mood dari user

    printf("\n---- Diary kamu dengan mood ");
    // Mengecek diary dengan mood mana yang cocok dengan yang diinput user
    if (pil == 1) {
        printf("Senang nih! ----\n"); }
    else if (pil == 2) {
        printf("Lagi sedih:( ----\n"); }
    else if (pil == 3) {
        printf("Biasa aja sihh:' ----\n"); }
    else if (pil == 4) {
        printf("Badmooddd -_- ----\n"); }
    else {
        printf("Pilihan tidak ada. Silakan pilih lagi.\n"); }
    
    for (int i = 0; i < jumlah; i++) {
    if (mood[i] == pil) { // Mengecek apakah mood diary ke-i sama dengan pilihan mood yang dicari user
        printf("Diary ke-%d:\n%s\n\n", i+1, diary[i]); // Jika cocok maka akan ditampilkan isi diary ke-i
        ketemu++; } // Menandai ada diary dengan mood yang sesuaii
    }

    if (ketemu == 0) { // Mengecek apakah diary sudah ketemu atau belum
    printf("Tidak ada diary dengan mood itu.\n"); } // Menampilkan pesan jika tidak ada diary yang cocok dengan mood yang dicari
}

// Fungsi utama program
int main() {
    cekPw(); // Memanggil dan menampilkan fungsi cekPw 

    int pil; // Variabel untuk menyimpan pilihan menu
    do {
        printf("\n=========== TRACKDIARY ===========\n"); // Menampilkan menu pilihan program
        printf("1. Tulis Diary\n2. Lihat Diary Berdasarkan Mood Kamu\n3. Keluar Program\n");
        printf("Kamu mau ngapain nih = "); 
        scanf("%d", &pil); // Membaca input pilihan menu dari user
        
        switch(pil) { // Mengecek pilihan user
            case 1:
                tulisDiary(); break; // Memanggil dan menampilkan fungsi tulisDiary
            case 2:
                cariDiary(); break; // Memanggil dan menampilkan fungsi cariDiary
            case 3:
                printf("Byee... Mampir lagi yaa!"); break;  // Untuk keluar dari program
            default:
                printf("Pilihan yang kamu pilih gak ada!\n"); // Untuk pilihan yang tidak ada atau tidak valid
        }
    } while(pil != 3);   // Program akan berjalan terus sampai user pilih 3 (keluar)
}