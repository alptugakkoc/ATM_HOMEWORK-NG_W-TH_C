/*
#include <stdio.h>
#include <string.h>

// Sezar Şifreleme Fonksiyonu
void sezarSifreleme(char* metin, int anahtar) {
    for (int i = 0; metin[i] != '\0'; i++) {
        char ch = metin[i];
        if (ch >= 'a' && ch <= 'z') { // Küçük harf
            metin[i] = ((ch - 'a' + anahtar) % 26) + 'a';
        } else if (ch >= 'A' && ch <= 'Z') { // Büyük harf
            metin[i] = ((ch - 'A' + anahtar) % 26) + 'A';
        }
        // Harf dışındaki karakterler olduğu gibi bırakılır
    }
}

// Sezar Şifre Çözme Fonksiyonu
void sezarSifreCozme(char* sifreliMetin, int anahtar) {
    for (int i = 0; sifreliMetin[i] != '\0'; i++) {
        char ch = sifreliMetin[i];
        if (ch >= 'a' && ch <= 'z') { // Küçük harf
            sifreliMetin[i] = ((ch - 'a' - anahtar + 26) % 26) + 'a';
        } else if (ch >= 'A' && ch <= 'Z') { // Büyük harf
            sifreliMetin[i] = ((ch - 'A' - anahtar + 26) % 26) + 'A';
        }
        // Harf dışındaki karakterler olduğu gibi bırakılır
    }
}

int main() {
    char metin[100];
    int anahtar;

    // Kullanıcıdan metin ve anahtar değeri alınır
    printf("Metni girin: ");
    fgets(metin, sizeof(metin), stdin); // Kullanıcıdan metni al
    metin[strcspn(metin, "\n")] = '\0'; // Sonundaki '\n' karakterini temizle

    printf("Anahtar değerini girin: ");
    scanf("%d", &anahtar);

    // Orijinal metni şifrele
    sezarSifreleme(metin, anahtar);
    printf("Şifreli metin: %s\n", metin);

    // Şifreli metni çöz
    sezarSifreCozme(metin, anahtar);
    printf("Çözülmüş metin: %s\n", metin);

    return 0;
}
---------------------------------
#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main() {
    char metin[1000];
    int i = 0, sayac = 0;

    //Metin alma işlemi
    printf("Bir metin giriniz : ");
    fgets(metin,sizeof(metin),stdin); //fgets ile metin aldık

    // Düz ünlü harfler
    char duz_unluler[] = "aeıioöuü";

    while(metin[i] != '\0') {
        if (isalpha(metin[i])) {
            char harf = tolower(metin[i]);
            if (strchr(duz_unluler,harf)){
                sayac++;
            }
        }
        i++;
    }
    printf("Metinde toplam %d adet düz ünlü harf bulunmaktadır . \n",sayac);


    return 0;
}
 
 // C Final Çalışmaları
// Soru 1)
/*
 * 1- Klavyeden alacağınız bir metni sezar şifreleme ile şifreleyip, sonra şifreli halinden tekrar orijinal
 * metni elde eden bir program yazınız.
 * (Şifreleme için bir fonksiyon, şifre çözme için ayrı bir fonksiyon yazınız.)

// Sezar şifreleme girilen metinde ki her harfi anahtar kadar kaydırarak şifreleme yöntemidir.

#include <stdio.h>  // Standart giriş ve çıkış işlemleri için gerekli kütüphane
#include <string.h> // String işlemleri (örneğin, fgets, strcspn) için gerekli kütüphane

// Şifreleme fonksiyonu
void sezarSifreleme(char *metin, int anahtar) {
    for (int i = 0; metin[i] != '\0'; i++) { // Metnin sonundaki '\0' karakterine kadar döngü
        if (metin[i] >= 'A' && metin[i] <= 'Z') { // Büyük harf kontrolü
            metin[i] = ((metin[i] - 'A' + anahtar) % 26) + 'A';
            // Büyük harfleri alfabedeki konumlarına göre kaydırır, %26 ile döngü sağlar
        } else if (metin[i] >= 'a' && metin[i] <= 'z') { // Küçük harf kontrolü
            metin[i] = ((metin[i] - 'a' + anahtar) % 26) + 'a';
            // Küçük harfleri alfabedeki konumlarına göre kaydırır, %26 ile döngü sağlar
        }
        // Harf olmayan karakterler (boşluk, noktalama işaretleri vb.) aynı kalır
    }
}

// Şifre çözme fonksiyonu
void sezarSifreCozme(char *metin, int anahtar) {
    sezarSifreleme(metin, -anahtar); // Şifre çözmek için şifreleme fonksiyonuna negatif anahtar gönderilir
}

int main() {
    char metin[100]; // Kullanıcıdan alınacak metin için karakter dizisi (string)
    int anahtar;     // Şifreleme ve çözme için kullanılacak anahtar

    printf("Metni giriniz: "); // Kullanıcıdan metni ister
    fgets(metin, sizeof(metin), stdin); // Kullanıcıdan bir satır metin alır
    metin[strcspn(metin, "\n")] = '\0'; // fgets ile alınan metindeki '\n' (yeni satır) karakterini '\0' ile değiştirir

    printf("Şifreleme anahtarını giriniz: "); // Kullanıcıdan şifreleme anahtarını ister
    scanf("%d", &anahtar); // Anahtarı alır

    // Şifreleme işlemi
    sezarSifreleme(metin, anahtar); // Kullanıcının girdiği metin ve anahtar ile şifreleme yapılır
    printf("Şifrelenmiş metin: %s\n", metin); // Şifrelenmiş metin ekrana yazdırılır

    // Şifre çözme işlemi
    sezarSifreCozme(metin, anahtar); // Şifrelenmiş metin ve anahtar ile şifre çözülür
    printf("Çözülmüş metin: %s\n", metin); // Çözülmüş (orijinal) metin ekrana yazdırılır

    return 0; // Programın başarılı bir şekilde sona erdiğini belirtir
}
*/

//Soru 2 )
/*
 *Klavyeden alacağınız bir metni aşağıdaki örnekte görüldüğü gibi sessiz ve sesli harfler ayrıştırılmış ve 
metnin orijinal yapısı hakkında bir string te tutarak metni ayrıştırın ve sonrasında tekrar orijinal haline 
dönüştürünüz. (Ayrıştıma için bir fonksiyon, orijinal haline dönüştürme için ayrı bir fonksiyon yazınız.)
 *"merhaba dunya nasilsiniz"
 sessiz :"mrhb dny nslsnz"
 sesli  :"eaauaaiii"
 yapı   : metni orijinal haline dönüştürmek için tutmanız gereken ilave verinin nasıl olması gerektiğini siz belirlemelisiniz
          bu veri minumum miktarda olmalıdır.
 *

 #include <stdio.h>
 #include <string.h>
 #include <ctype.h>
#include <iso646.h>

#define SESLI_HARFLER "aeiouAEIOU"
 // Ayrıştırma fonksiyonu
void ayrisma(const char *metin, char *sessiz, char *sesli, char *yapi) {
    int sessiz_index = 0, sesli_index = 0;

    for (int i = 0; metin[i] != '\0'; i++) {
        if (strchr(SESLI_HARFLER, metin[i])) { // Sesli harf kontrolü
            sesli[sesli_index++] = metin[i];  // Sesli harf stringine ekle
            yapi[i] = 's'; // Sesli harfi işaretle
        } else if (isalpha(metin[i])) { // Sessiz harf kontrolü
            sessiz[sessiz_index++] = metin[i]; // Sessiz harf stringine ekle
            yapi[i] = 'c'; // Sessiz harfi işaretle
        } else {
            yapi[i] = metin[i]; // Harf değilse (boşluk gibi), doğrudan yapıya ekle
        }
    }

    // Ayrıştırılan stringlerin sonuna null karakter ekle
    sessiz[sessiz_index] = '\0';
    sesli[sesli_index] = '\0';
    yapi[strlen(metin)] = '\0'; // Yapının sonunu belirt
}

// Orijinal haline dönüştürme fonksiyonu
void orijinaleDonustur(const char *sessiz, const char *sesli, const char *yapi, char *orijinal) {
    int sessiz_index = 0, sesli_index = 0;

    for (int i = 0; yapi[i] != '\0'; i++) {
        if (yapi[i] == 'c') { // Sessiz harfse
            orijinal[i] = sessiz[sessiz_index++]; // Sessiz harf stringinden al
        } else if (yapi[i] == 's') { // Sesli harfse
            orijinal[i] = sesli[sesli_index++]; // Sesli harf stringinden al
        } else {
            orijinal[i] = yapi[i]; // Harf değilse (örneğin boşluk), doğrudan ekle
        }
    }

    // Orijinal stringin sonuna null karakter ekle
    orijinal[strlen(yapi)] = '\0';
}

int main() {
    char metin[100],sessiz[100],sesli[100],yapi[100],orijinal[100];
    // KULLANICIDAN METIN ALMA
    printf("Lütfen Metin giriniz: ");
    fgets(metin,sizeof(metin),stdin);
    metin[strcspn(metin,"\n")] = '\0';

    //AYRIŞTIRMA İŞLEMİ
    ayrisma(metin,sessiz,sesli,yapi);

    //Soonucları yazdir
    printf("Sessiz harfler : \"%s\"\n",sessiz);
    printf("Sesli harfler : \"%s\"\n",sesli);
    printf("Yapi harfler : \"%s\"\n",yapi);

    //Orjinal haline dönüştürme
    orijinaleDonustur(sessiz,sesli,yapi,orijinal);

    //Orjinal metni yazdir
    printf("Orjinal metin : \"%s\"\n",orijinal);



    return 0;
}
--------------------
// Soru 3 )
// Klavyeden bir metin alarak bu metin içerisinde toplam kaç adet düz ünlü harf olduğunu bularak ekrana
// görüntüleyecek bir c programı yazınız .

#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main() {
    char metin[1000];
    int i = 0, sayac = 0;

    //Metin alma işlemi
    printf("Bir metin giriniz : ");
    fgets(metin,sizeof(metin),stdin); //fgets ile metin aldık

    // Düz ünlü harfler
    char duz_unluler[] = "aeıioöuü";

    while(metin[i] != '\0') {
        if (isalpha(metin[i])) {
            char harf = tolower(metin[i]);
            if (strchr(duz_unluler,harf)){
                sayac++;
            }
        }
        i++;
    }
    printf("Metinde toplam %d adet düz ünlü harf bulunmaktadır . \n",sayac);


    return 0;
}


//SORU 4
// Bir uygulamada kullanıcının şifresinin belirli kurallara uyması istenmektedir . Buna göre ;
// -Şifre en az 8 karakter olmalıdır .
// -Şifrede en az bir büyük , en az bir küçük harf ve en az 1 rakam olmalıdır .
// Parametre olarak şifreyi alıp, alınan şifre bu kuralların tamamına uygunsa geriye 1 , değilse geriye 0 değerini döndüren C dili fonksiyonu yazınız .

#include <stdio.h>
#include <ctype.h>  // isdigit(), isupper(), islower() fonksiyonları için
#include <string.h> // strlen() fonksiyonu için

int sifreKontrolu(const char* sifre) {
    // Şifrenin uzunluğu 8 karakterden küçükse hemen 0 döndür
    if (strlen(sifre) < 8) {
        return 0;
    }

    int buyukHarf = 0, kucukHarf = 0, rakam = 0;

    // Şifreyi kontrol et
    for (int i = 0; sifre[i] != '\0'; i++) {
        if (isupper(sifre[i])) {  // Büyük harf kontrolü
            buyukHarf = 1;
        }
        if (islower(sifre[i])) {  // Küçük harf kontrolü
            kucukHarf = 1;
        }
        if (isdigit(sifre[i])) {  // Rakam kontrolü
            rakam = 1;
        }
    }

    // Tüm kurallara uyuluyorsa 1 döndür
    if (buyukHarf && kucukHarf && rakam) {
        return 1;
    }

    // Kurallara uymuyorsa 0 döndür
    return 0;
}

int main() {
    char sifre[100];

    // Kullanıcıdan şifreyi al
    printf("Bir sifre girin: ");
    scanf("%s", sifre);

    // Şifreyi kontrol et
    if (sifreKontrolu(sifre)) {
        printf("Sifre dogru.\n");
    } else {
        printf("Sifre kurallara uymuyor.\n");
    }

    return 0;
}

// Soru 5
// Kullanıcıdan aldığı bir metni , yine kullanıcıdan aldığı bir tam sayı anahtar ile sezar şifrelemesi kullanarak şifreleyip ekrana metnin şifreli halini görüntüleyecek
// C programını yaz.

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
    void sezarSifrele (char*metin,int anahtar) {
        //Metinde ki her karakteri şifrele
        for (int i=0; metin[i] != '\0';i++) {
            //Eğer karakter bir harf ise
            if (isalpha(metin[i])) {
                //Küçük harfler için
                if (islower(metin[i])) {
                    metin[i] = ((metin[i]- 'a' + anahtar) % 26 ) +'a';
                }
                //Büyük harfler için
                else if (isupper(metin[i])) {
                    metin[i] = ((metin[i]- 'A' + anahtar) % 26) + 'A';
                }
            }
        }
    }

int main() {
    char metin[1000];
    int anahtar;

    printf("Metin giriniz: ");
    fgets(metin,sizeof(metin),stdin);

    printf("Bir anahtar değeri giriniz: ");
    scanf("%d",&anahtar);

    sezarSifrele(metin,anahtar);

    printf("Sifrelenmis metin: %s",metin);
    return 0;
}


//Soru 6
//Bir grup hastanın boy(metre) , kilo(kg) , yaş(yıl) ve cinsiyet bilgileri verilecektir. Yazacağınız program hastalara ait bu verileri klavyeden alarak
//eğer hasta normal kiloda ise hasta bilgilerini "normal.dat"  dosyasına , hasta normal kiloda değilse "normal_D.dat" dosyasına kayıt edecektir.
// Vücüt kitle endeksi(E) = kilo(kg)/boy*boy(metre) , E değeri [18,5-25] ise hasta normal kiloludur.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    float boy,kilo;
    int yas;
    char cinsiyet;

    printf("Hastanın boyunu giriniz: ");
    scanf("%f,&boy");
    printf("Hastanın kilosunu giriniz: ");
    scanf("%f",&kilo);
    printf("Hastanin yasini giriniz: ");
    scanf("%d",&yas);
    printf("Hastanin cinsiyetini giriniz(E/K): ");
    scanf("%c",&cinsiyet);

    float bmi = kilo/(boy*boy);

    if (bmi >=18.5 && bmi <=24.9) {
        //kilo normal
        FILE*fp=fopen("normal.dat","a");
        fprintf(fp,"Boy: %2.f metre\n",boy);
        fprintf(fp,"Kilo: %2.f kg\n",kilo);
        fprintf(fp,"Yas: %2.f yil\n",yas);
        fprintf(fp,"Cinsiyet %c\n",cinsiyet);
        fclose(fp);
        printf("Hastanin bilgileri normal.dat dosyasina kaydedildi.\n");
    }
    else {
        //Kilo fazla
        FILE*fp=fopen("normal_D.dat","a");
        fprintf(fp,"Boy: %2.f metre\n",boy);
        fprintf(fp,"Kilo: %2.f kg\n",kilo);
        fprintf(fp,"Yas: %2.f yil\n",yas);
        fprintf(fp,"Cinsiyet %c\n",cinsiyet);
        fclose(fp);
        printf("Hastanin bilgileri normal_D.dat dosyasına kayit edildi.\n");
    }


    return 0;
}

//Soru 7
// Parametre olarak santigrat cinsi sıcaklık değerini alarak bu değerin Fahrenheit değeri karşısılığını bulan ve geriye döndüren bir fonksiyon yaz.
// Fahrenheit = Santigrat*1.8 + 32)

float santigratToFahrenheit (float santigrat) {
    return (santigrat *1.8) +32;
}

// Soru 8 )
//cift_ayir isimli fonksiyon 3 adet parametre alacaktır , bu parametrelerden Birincisi içinde tamsayı değerler olan bir dizidir . İkincisi ise bu tamsayı dizisinin
//eleman sayısıdır . Üçünci parametre yine n elemanlı boş bir tamsayı dizisidir .
// Fonksiyon 1. parametre ile verilen dizideki çift sayıları belirleyip 3 parametre ile verilen diziye atayacak ve bu diziye kaç adet çift sayı atadığını geri döndürecektir.

#include <stdio.h>

int cift_ayir(int dizi[], int n, int sonuc[]) {
    int sayac = 0;
    for (int i = 0; i < n; i++) {
        if (dizi[i] % 2 == 0) {  // Eğer sayı çiftse
            sonuc[sayac] = dizi[i];  // Sonuç dizisine ekle
            sayac++;  // Sayaç artır
        }
    }
    return sayac;  // Çift sayıların sayısını döndür
}

int main() {
    int dizi[] = {1, 2, 3, 4, 5, 6, 7, 8};  // Örnek dizi
    int n = sizeof(dizi) / sizeof(dizi[0]);  // Dizinin eleman sayısı
    int sonuc[n];  // Çift sayılar için boş bir dizi

    int cift_sayisi = cift_ayir(dizi, n, sonuc);

    printf("Çift sayılar (%d adet): ", cift_sayisi);
    for (int i = 0; i < cift_sayisi; i++) {
        printf("%d ", sonuc[i]);
    }
    printf("\n");

    return 0;
}

* Kullanıcı gizli bir metni bir dosyada saklamak ve gerektiğinde okumak istiyordur.
 * Ancak metin dosyası açıldığından metnin okunabilir olmasını istemiyordur.
 * Bunun için Sezar şifreleme kullanarak yazılan bir metni şifreleyerek kaydeden
 * sonra kaydettiği metni okurken şifreyi çözerek ekrana gösteren bir C programı yazınız.
 * Kullanıcı programı açtığında metni okuma veya dosya içeriğini değiştirme seçeneği sunulacaktır.
 * SEZAR ŞİFRELEME: Her bir karakterin değerinin belli bir tam sayı anahtar kadar
 * ASCII tablosunda ilerletilmesiyle yapılabilir. Örnek anahtar 1 olsun A->B olur.
 * Anahtar 2 olsa A->C olur. Şifre açılırken de anahtar kadar geri döndürme yapılır.
 * Dosya adı ve anahtarı kodda verebilirsiniz.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define DOSYA_ADI "sifreli_metin.txt"
#define ANAHTAR 3 // Sezar şifreleme anahtarı

// Metni Sezar şifreleme algoritması ile şifrele
void metniSifrele(char* metin, int anahtar) {
    for (int i = 0; metin[i] != '\0'; i++) {
        if (metin[i] >= 32 && metin[i] <= 126) { // Yazdırılabilir karakterleri şifrele
            metin[i] = (metin[i] + anahtar);
            if (metin[i] > 126) {
                metin[i] -= 95; // Yazdırılabilir karakter aralığını aşarsa başa sar
            }
        }
    }
}

// Şifrelenmiş metni çöz
void sifreCoz(char* metin, int anahtar) {
    for (int i = 0; metin[i] != '\0'; i++) {
        if (metin[i] >= 32 && metin[i] <= 126) { // Yazdırılabilir karakterleri çöz
            metin[i] = (metin[i] - anahtar);
            if (metin[i] < 32) {
                metin[i] += 95; // Yazdırılabilir karakter aralığından çıkarsa sona sar
            }
        }
    }
}

// Dosyaya şifrelenmiş metni kaydet
void metniDosyayaKaydet(char* metin) {
    FILE* dosya = fopen(DOSYA_ADI, "w");
    if (dosya == NULL) {
        printf("Dosya açılamadı!\n");
        return;
    }

    metniSifrele(metin, ANAHTAR);
    fprintf(dosya, "%s", metin);
    fclose(dosya);

    printf("Metin başarıyla dosyaya şifrelenerek kaydedildi.\n");
}

// Dosyadan şifrelenmiş metni oku ve çöz
void dosyadanMetinOku() {
    FILE* dosya = fopen(DOSYA_ADI, "r");
    if (dosya == NULL) {
        printf("Dosya açılamadı! Henüz bir metin kaydedilmemiş olabilir.\n");
        return;
    }

    char metin[1024];
    if (fgets(metin, sizeof(metin), dosya) == NULL) {
        printf("Dosyada herhangi bir veri bulunamadı.\n");
        fclose(dosya);
        return;
    }

    fclose(dosya);
    sifreCoz(metin, ANAHTAR);
    printf("Dosyadaki şifre çözülmüş metin: %s\n", metin);
}

int main() {
    int secim;
    char metin[1024];

    while (1) {
        printf("\n--- Metin Yönetim Sistemi ---\n");
        printf("1. Dosyadan Metni Oku\n");
        printf("2. Dosya İçeriğini Değiştir\n");
        printf("0. Çıkış\n");
        printf("Seçiminizi yapın: ");
        scanf("%d", &secim);
        getchar(); // Boşluk karakterlerini temizle

        switch (secim) {
            case 1:
                dosyadanMetinOku();
                break;
            case 2:
                printf("Yeni metni girin: ");
                fgets(metin, sizeof(metin), stdin);
                metin[strcspn(metin, "\n")] = '\0'; // Satır sonu karakterini kaldır
                metniDosyayaKaydet(metin);
                break;
            case 0:
                printf("Programdan çıkılıyor. İyi günler!\n");
                return 0;
            default:
                printf("Geçersiz seçim! Lütfen tekrar deneyin.\n");
        }
    }

    return 0;
}

// Kullanıcıdan bir sayı tahmini alarak 1-100 arasında rastgele seçilen bir sayıyı tahmin etmesini sağla
//Kullanıcının belirli bir deneme hakkı olsun

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "Turkish");
    int sayi, tahmin, deneme_hakki = 5; // Değer 5 olarak tanımlanmış

    srand(time(NULL));
    sayi = rand() % 100 + 1; // 1 ile 100 arasında sayı türet

    printf("Bir sayı tuttum (1 ile 100 arasında). Tahminin nedir?\n");

    while (deneme_hakki > 0) {
        printf("Tahmininizi girin (%d hakkınız kaldı): ", deneme_hakki);
        scanf("%d", &tahmin);

        if (tahmin == sayi) {
            printf("Tebrikler! Sayıyı doğru tahmin ettiniz.\n");
            return 0;
        }
        else if (tahmin < sayi) {
            printf("Daha büyük bir sayı girin.\n");
        }
        else {
            printf("Daha küçük bir sayı girin.\n");
        }

        deneme_hakki--;
    }

    printf("Üzgünüm, bilemediniz. Doğru sayı %d idi.\n", sayi);
    return 0;
}

Soru:
C dilinde bir "Öğrenci Yönetim Sistemi" programı yazınız. Bu sistem aşağıdaki özelliklere sahip olmalıdır:

Bir öğrencinin adını, yaşını ve notunu saklayan bir yapı tanımlayın.
Öğrencinin bilgilerini ekrana yazdıran bir fonksiyon yazın.
Öğrencinin bilgilerini güncelleyen bir fonksiyon yazın.
Kullanıcıya bir menü sunarak, bu özellikler arasında seçim yapmasını sağlayın.
Kullanıcı "Çıkış" seçeneğini seçtiğinde program sonlanmalıdır.


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>

typedef struct {
    char ad[50];
    int yas;
    float notu;
} Ogrenci;

void bilgileriGoster(Ogrenci* ogr) {
    printf("\n--- Öğrenci Bilgileri ---\n");
    printf("Ad: %s\n", ogr->ad);
    printf("Yaş: %d\n", ogr->yas);
    printf("Not: %.2f\n", ogr->notu);
}

void bilgileriGuncelle(Ogrenci* ogr) {
    printf("\n--- Öğrenci Bilgilerini Güncelle ---\n");
    printf("Yeni Ad: ");
    scanf(" %[^\n]s", ogr->ad);
    printf("Yeni Yaş: ");
    scanf("%d", &ogr->yas);
    printf("Yeni Not: ");
    scanf("%f", &ogr->notu);
}

int main() {
    setlocale(LC_ALL, "Turkish");

    Ogrenci ogrenci1 = { "Ahmet", 20, 85.5 };
    int secim;

    while (1) {
        printf("\n--- Öğrenci Yönetim Sistemi ---\n");
        printf("1. Bilgileri Göster\n");
        printf("2. Bilgileri Güncelle\n");
        printf("0. Çıkış\n");
        printf("Seçiminizi yapın: ");
        scanf("%d", &secim);

        switch (secim) {
            case 1:
                bilgileriGoster(&ogrenci1);
            break;
            case 2:
                bilgileriGuncelle(&ogrenci1);
            break;
            case 0:
                printf("Çıkış yapılıyor. İyi günler!\n");
            return 0;
            default:
                printf("Geçersiz seçim! Lütfen tekrar deneyin.\n");
        }
    }

    return 0;
}

// KÜTÜPHANE OTOMASYONU
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <locale.h>

#define MAKS_KITAP 100

typedef struct {
	char kitap_adi[100];
	char yazar_adi[100];
	char isbn[20];
	} Kitap;

int main() {
	setlocale("lC_ALL","tr_TR.UTF-9");

	Kitap kutuphane[MAKS_KITAP];
	int kitap_sayisi = 0;
	int secim;

	while (1) {
		printf("\n--- Kütüphane Yönetim Sistemi ---\n");
		printf("1. Yeni Kitap Ekle\n");
		printf("2. Tüm Kitapları Listele\n");
		printf("3. ISBN ile Kitap Ara\n");
		printf("0. Çıkış\n");
		printf("Seçiminizi yapın: ");
		scanf("%d", &secim);

		switch (secim) {
				case 1: {
					if (kitap_sayisi < MAKS_KITAP) {
						printf("Kitap adını girin: ");
						scanf(" %[^\n]s", kutuphane[kitap_sayisi].kitap_adi);
						printf("Yazar adını girin: ");
						scanf(" %[^\n]s", kutuphane[kitap_sayisi].yazar_adi);
						printf("ISBN numarasını girin: ");
						scanf(" %[^\n]s", kutuphane[kitap_sayisi].isbn);
						kitap_sayisi++;
						printf("Kitap başarıyla eklendi!\n");
						}
					else {
						printf("Kütüphane dolu! Daha fazla kitap eklenemez.\n");
						}
					break;
					}
				case 2:
					if (kitap_sayisi > 0) {
						printf("\n--- Kitap Listesi ---\n");
						for (int i = 0; i < kitap_sayisi; i++) {
							printf("%d. Kitap: %s, Yazar: %s, ISBN: %s\n",
								   i + 1,
								   kutuphane[i].kitap_adi,
								   kutuphane[i].yazar_adi,
								   kutuphane[i].isbn);
							}
						}
					else {
						printf("Kütüphanede henüz kitap yok.\n");
						}
					break;

				case 3: {
					char aranan_isbn[20];
					printf("Aramak istediğiniz ISBN numarasını girin: ");
					scanf(" %[^\n]s", aranan_isbn);
					int bulundu = 0;

					for (int i = 0; i < kitap_sayisi; i++) {
						if (strcmp(kutuphane[i].isbn, aranan_isbn) == 0) {
							printf("Kitap bulundu: %s, Yazar: %s, ISBN: %s\n",
								   kutuphane[i].kitap_adi,
								   kutuphane[i].yazar_adi,
								   kutuphane[i].isbn);
							bulundu = 1;
							break;
							}
						}
					if (!bulundu) {
						printf("Bu ISBN numarasıyla eşleşen kitap bulunamadı.\n");
						}
					break;
					}
				case 0:
					printf("Çıkış yapılıyor. İyi günler!\n");
					return 0;

				default:
					printf("Geçersiz seçim! Lütfen tekrar deneyin.\n");
			}
		}

	return 0;
	}
--------------- basit ATM OTOMASYONU -----------------
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "Turkish");

    int secim;
    float bakiye = 1000.0, miktar;

    while (1) {
        printf("\n--- ATM Uygulaması ---\n");
        printf("1. Bakiye Kontrolü\n");
        printf("2. Para Yatırma\n");
        printf("3. Para Çekme\n");
        printf("0. Çıkış\n");
        printf("Seçiminizi yapın: ");
        scanf("%d", &secim);

        switch (secim) {
            case 1:
                printf("Mevcut bakiyeniz: %.2f TL\n", bakiye);
            break;

            case 2:
                printf("Yatırmak istediğiniz miktarı girin: ");
            scanf("%f", &miktar);
            if (miktar > 0) {
                bakiye += miktar;
                printf("%.2f TL yatırıldı. Yeni bakiyeniz: %.2f TL\n", miktar, bakiye);
            }
            else {
                printf("Geçersiz miktar!\n");
            }
            break;

            case 3:
                printf("Çekmek istediğiniz miktarı girin: ");
            scanf("%f", &miktar);
            if (miktar > 0 && miktar <= bakiye) {
                bakiye -= miktar;
                printf("%.2f TL çekildi. Kalan bakiyeniz: %.2f TL\n", miktar, bakiye);
            }
            else if (miktar > bakiye) {
                printf("Yetersiz bakiye!\n");
            }
            else {
                printf("Geçersiz miktar!\n");
            }
            break;

            case 0:
                printf("Çıkış yapılıyor. İyi günler!\n");
            return 0;

            default:
                printf("Geçersiz seçim! Lütfen tekrar deneyin.\n");
        }
    }

    return 0;
}


#include <stdio.h>

int main() {
    int i, j, asal;

    printf("1'den 100'e kadar olan asal sayilar:\n");

    for (i = 2; i <= 100; i++) { // 2'den 100'e kadar her sayıyı kontrol et
        asal = 1; // Başlangıçta sayıyı asal kabul et
        for (j = 2; j <= i / 2; j++) { // Sayıyı bölmek için 2'den i/2'ye kadar kontrol et
            if (i % j == 0) { // Eğer tam bölünüyorsa asal değildir
                asal = 0;
                break; // Asal olmadığını anladık, döngüden çık
            }
        }
        if (asal == 1) { // Eğer asal kaldıysa ekrana yazdır
            printf("%d ", i);
        }
    }

    return 0;
}
-------------------
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "Turkish");
    int sayi, tahmin, deneme_hakki = 5;

    srand(time(NULL));
    sayi = rand() % 100 + 1;

    printf("Bir sayı tuttum (1 ile 100 arasında). Tahminin nedir?\n");

    while (deneme_hakki > 0) {
        printf("Tahmininizi girin (%d hakkınız kaldı): ", deneme_hakki);
        scanf("%d", &tahmin);

        if (tahmin == sayi) {
            printf("Tebrikler! Sayıyı doğru tahmin ettiniz.\n");
            return 0;
        }
        else if (tahmin < sayi) {
            printf("Daha büyük bir sayı girin.\n");
        }
        else {
            printf("Daha küçük bir sayı girin.\n");
        }

        deneme_hakki--;
    }

    printf("Üzgünüm, bilemediniz. Doğru sayı %d idi.\n", sayi);
    return 0;
}

-------------------------
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>

typedef struct {
    char ad[50];
    int yas;
    float notu;
} Ogrenci;

void bilgileriGoster(Ogrenci* ogr) {
    printf("\n--- Öğrenci Bilgileri ---\n");
    printf("Ad: %s\n", ogr->ad);
    printf("Yaş: %d\n", ogr->yas);
    printf("Not: %.2f\n", ogr->notu);
}

void bilgileriGuncelle(Ogrenci* ogr) {
    printf("\n--- Öğrenci Bilgilerini Güncelle ---\n");
    printf("Yeni Ad: ");
    scanf(" %[^\n]s", ogr->ad);
    printf("Yeni Yaş: ");
    scanf("%d", &ogr->yas);
    printf("Yeni Not: ");
    scanf("%f", &ogr->notu);
}

int main() {
    setlocale(LC_ALL, "Turkish");

    Ogrenci ogrenci1 = { "Ahmet", 20, 85.5 };
    int secim;

    while (1) {
        printf("\n--- Öğrenci Yönetim Sistemi ---\n");
        printf("1. Bilgileri Göster\n");
        printf("2. Bilgileri Güncelle\n");
        printf("0. Çıkış\n");
        printf("Seçiminizi yapın: ");
        scanf("%d", &secim);

        switch (secim) {
            case 1:
                bilgileriGoster(&ogrenci1);
            break;
            case 2:
                bilgileriGuncelle(&ogrenci1);
            break;
            case 0:
                printf("Çıkış yapılıyor. İyi günler!\n");
            return 0;
            default:
                printf("Geçersiz seçim! Lütfen tekrar deneyin.\n");
        }
    }

    return 0;
}
---------------------------
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <locale.h>

#define MAKS_KITAP 100

typedef struct {
	char kitap_adi[100];
	char yazar_adi[100];
	char isbn[20];
	} Kitap;

int main() {
	setlocale(LC_ALL, "Turkish");

	Kitap kutuphane[MAKS_KITAP];
	int kitap_sayisi = 0;
	int secim;

	while (1) {
		printf("\n--- Kütüphane Yönetim Sistemi ---\n");
		printf("1. Yeni Kitap Ekle\n");
		printf("2. Tüm Kitapları Listele\n");
		printf("3. ISBN ile Kitap Ara\n");
		printf("0. Çıkış\n");
		printf("Seçiminizi yapın: ");
		scanf("%d", &secim);

		switch (secim) {
				case 1: {
					if (kitap_sayisi < MAKS_KITAP) {
						printf("Kitap adını girin: ");
						scanf(" %[^\n]s", kutuphane[kitap_sayisi].kitap_adi);
						printf("Yazar adını girin: ");
						scanf(" %[^\n]s", kutuphane[kitap_sayisi].yazar_adi);
						printf("ISBN numarasını girin: ");
						scanf(" %[^\n]s", kutuphane[kitap_sayisi].isbn);
						kitap_sayisi++;
						printf("Kitap başarıyla eklendi!\n");
						}
					else {
						printf("Kütüphane dolu! Daha fazla kitap eklenemez.\n");
						}
					break;
					}
				case 2:
					if (kitap_sayisi > 0) {
						printf("\n--- Kitap Listesi ---\n");
						for (int i = 0; i < kitap_sayisi; i++) {
							printf("%d. Kitap: %s, Yazar: %s, ISBN: %s\n",
								   i + 1,
								   kutuphane[i].kitap_adi,
								   kutuphane[i].yazar_adi,
								   kutuphane[i].isbn);
							}
						}
					else {
						printf("Kütüphanede henüz kitap yok.\n");
						}
					break;

				case 3: {
					char aranan_isbn[20];
					printf("Aramak istediğiniz ISBN numarasını girin: ");
					scanf(" %[^\n]s", aranan_isbn);
					int bulundu = 0;

					for (int i = 0; i < kitap_sayisi; i++) {
						if (strcmp(kutuphane[i].isbn, aranan_isbn) == 0) {
							printf("Kitap bulundu: %s, Yazar: %s, ISBN: %s\n",
								   kutuphane[i].kitap_adi,
								   kutuphane[i].yazar_adi,
								   kutuphane[i].isbn);
							bulundu = 1;
							break;
							}
						}
					if (!bulundu) {
						printf("Bu ISBN numarasıyla eşleşen kitap bulunamadı.\n");
						}
					break;
					}
				case 0:
					printf("Çıkış yapılıyor. İyi günler!\n");
					return 0;

				default:
					printf("Geçersiz seçim! Lütfen tekrar deneyin.\n");
			}
		}

	return 0;
	}
-----------------------------------

 * Kullanıcı adlarını ve şifrelerini tutmak üzere bir struct tanımlayınız.
 * Okunur mod ile dosya açıp bu bilgileri dosyadan okuyunuz. (fscanf ile)
 * Kayıtlı kullanıcı sayısını ekrana yazdırınız.
 * Daha sonra okunan kullanıcı adı ve şifrelerini ekrana yazdırınız.
 * Yeni kullanıcı kaydı eklemek isterseniz 1'e (append(a) modu ile),
 * kullanıcı girişi yapmak için 2'ye basınız seçim ekranını oluşturunuz.
 * Kullanıcı 1'e basarsa dosyaya kaydı yazdırınız.
 * 2'ye basarsa kullanıcıdan alınan kullanıcı adı ve şifresini dosyadaki kayıt bilgileriyle karşılaştırınız(strcmp)
 * Sistemdeki bir kullanıcı ise giriş yapan ekrana, bu kullanıcı giriş yaptı yazdırınız.



#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>


// Kullanıcı adı ve şifrelerini saklamak için bir struct tanımlayalım.
struct Kullanici {
    char kadi[30];
    char sifre[30];
};
Kullanici kullanicilar[10]; // 10 kullanıcı tanımlayalım.

int main() {

    // Tüm kullanıcıları dosyadan okuyalım

    char dosyakonum[50] = "C:\\Users\\oguz\\Desktop\\kullanicilar.txt";
    FILE* dosya;
    dosya = fopen(dosyakonum, "r");
    int i = 0;
    if (dosya == NULL) {
        printf("Dosya yok!.\n");
    }
    else{
    while (!feof(dosya)) {
        fscanf(dosya, "%s %s", kullanicilar[i].kadi, kullanicilar[i].sifre);
        i++;
    }
    fclose(dosya);
    }
    // Kayıtlı kullanıcı sayısını ekrana yazdır.
    printf("Kayitli kullanici sayisi: %d\n", i);
    // Kullanıcı adı ve şifrelerini ekrana yazdır.

    for (int j = 0; j < i; j++) {
        printf("%s %s", kullanicilar[j].kadi, kullanicilar[j].sifre);
    }

    // Yeni kullanıcı oluşturma ya da giriş yapma menüsü
    int secim;
    printf("\nYeni kullanici olusturmak icin 1'e basiniz.\n");
    printf("Giris yapmak icin 2'ye basiniz.\n");
    scanf("%d", &secim);
    if (secim == 1) {
        // Yeni kullanıcı oluşturma
        char kadi[30];
        char sifre[30];
        printf("Kullanici adi giriniz: ");
        scanf("%s", kadi);
        printf("Sifre giriniz: ");
        scanf("%s", sifre);
        // Dosyaya yeni kullanıcıyı ekle
        FILE* dosya = fopen(dosyakonum, "a");
        fprintf(dosya, "%s %s", kadi, sifre);
        fclose(dosya);
    }
    else if (secim == 2) {
        // Giriş yapma
        char kadi[30];
        char sifre[30];
        printf("Kullanici adi giriniz: ");
        scanf("%s", kadi);
        printf("Sifre giriniz: ");
        scanf("%s", sifre);
        // Kullanıcı adı ve şifre doğru mu kontrol et
        int girisid = -1;
        for (int j = 0; j < i; j++) {
            if (strcmp(kadi, kullanicilar[j].kadi) == 0 && strcmp(sifre, kullanicilar[j].sifre) == 0) {
                girisid = j;
            }
        }
        if (girisid == -1) { printf("Kullanici adi veya sifre hatali"); }
        else { printf("%s olarak giris yapildi", kullanicilar[girisid].kadi); }
    }


    return 0;

}

----------------------------------------------------------

 * Kullanıcı gizli bir metni bir dosyada saklamak ve gerektiğinde okumak istiyordur.
 * Ancak metin dosyası açıldığından metnin okunabilir olmasını istemiyordur.
 * Bunun için Sezar şifreleme kullanarak yazılan bir metni şifreleyerek kaydeden
 * sonra kaydettiği metni okurken şifreyi çözerek ekrana gösteren bir C programı yazınız.
 * Kullanıcı programı açtığında metni okuma veya dosya içeriğini değiştirme seçeneği sunulacaktır.
 * SEZAR ŞİFRELEME: Her bir karakterin değerinin belli bir tam sayı anahtar kadar
 * ASCII tablosunda ilerletilmesiyle yapılabilir. Örnek anahtar 1 olsun A->B olur.
 * Anahtar 2 olsa A->C olur. Şifre açılırken de anahtar kadar geri döndürme yapılır.
 * Dosya adı ve anahtarı kodda verebilirsiniz.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

#define SIFRELEME_ANAHTARI 3

// Fonksiyon prototipleri
void sifreleme(char *str);
void desifreleme(char *str);
void dosyayioku(char *dosyaadi);
void dosyayayaz(char *dosyaadi);

int main(int argc, char *argv[]) {
    // Dosya adı sabit olarak tanımlanmış olsun.
    char *dosyaadi = "test.txt";
    // Menü ekranı
    int secim = 0;
    while (secim != 3) {
        printf("\nMenu:\n");
        printf("1. Dosyayi goruntule\n");
        printf("2. Dosya icerigini degistir.\n");
        printf("3. Cikis\n");
        printf("Seciminizi giriniz: ");
        scanf("%d", &secim);


        switch (secim) {
            case 1:
                dosyayioku(dosyaadi);
                break;
            case 2:
                dosyayayaz(dosyaadi);
                break;
            case 3:
                break;
            default:
                printf("Hatali giris\n");
                break;
        }
    }

    return 0;
}

// Dosya içeriğini oku
void dosyayioku(char *dosyaadi) {
    char buffer[BUFFER_SIZE];

    //Okuma için dosyayı r modunda açıyoruz.
    FILE *file = fopen(dosyaadi, "r");
    if (file == NULL) {
        printf("HATA: Dosya açılamadı\n");
        return;
    }

    // Buffer size değeri kadar dosyayı oku
    while (fgets(buffer, BUFFER_SIZE, file) != NULL) {
    // Buffer (tampon) veriyi desifrele
        desifreleme(buffer);
        // Deşifrelenmiş veriyi ekrana yazdır.
        printf("%s", buffer);
    }

// Dosyayı kapat.
    fclose(file);
}

// Dosya içeriğini değiştirmek için fonk.
void dosyayayaz(char *dosyaadi) {
    char buffer[BUFFER_SIZE];

    // Dosya yazma modu olan w ile açıyoruz.
    FILE *file = fopen(dosyaadi, "w");
    if (file == NULL) {
        printf("Dosya açılamadı.\n");
        return;
    }

    // Kullanıcıdan yeni metni al
    printf("Yeni dosya içeriğini giriniz: ");
    getchar();
    scanf("%[^\n]", buffer);



    //Dosya içeriğini şifrele
    sifreleme(buffer);

    //Şifrelenmiş içeriği dosyaya yazdır.
    fputs(buffer, file);

    //Dosyayı kapat.
    fclose(file);
}

// Şifreleme fonksiyonu
void sifreleme(char *str) {
    for (int i = 0; i < strlen(str); i++) {
    // Karakteri kaydır.
        str[i] = (str[i] + SIFRELEME_ANAHTARI) % 256;
    }
}

// Şifre açma fonksiyonu
void desifreleme(char *str) {
    for (int i = 0; i < strlen(str); i++) {
    // Karakteri tersten kaydır.
        str[i] = (str[i] - SIFRELEME_ANAHTARI + 256) % 256;
    }
}
---------------------------------------
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "Turkish");

    int secim;
    float bakiye = 1000.0, miktar;

    while (1) {
        printf("\n--- ATM Uygulaması ---\n");
        printf("1. Bakiye Kontrolü\n");
        printf("2. Para Yatırma\n");
        printf("3. Para Çekme\n");
        printf("0. Çıkış\n");
        printf("Seçiminizi yapın: ");
        scanf("%d", &secim);

        switch (secim) {
                case 1:
                    printf("Mevcut bakiyeniz: %.2f TL\n", bakiye);
                    break;

                case 2:
                    printf("Yatırmak istediğiniz miktarı girin: ");
                    scanf("%f", &miktar);
                    if (miktar > 0) {
                        bakiye += miktar;
                        printf("%.2f TL yatırıldı. Yeni bakiyeniz: %.2f TL\n", miktar, bakiye);
                        }
                    else {
                        printf("Geçersiz miktar!\n");
                        }
                    break;

                case 3:
                    printf("Çekmek istediğiniz miktarı girin: ");
                    scanf("%f", &miktar);
                    if (miktar > 0 && miktar <= bakiye) {
                        bakiye -= miktar;
                        printf("%.2f TL çekildi. Kalan bakiyeniz: %.2f TL\n", miktar, bakiye);
                        }
                    else if (miktar > bakiye) {
                        printf("Yetersiz bakiye!\n");
                        }
                    else {
                        printf("Geçersiz miktar!\n");
                        }
                    break;

                case 0:
                    printf("Çıkış yapılıyor. İyi günler!\n");
                    return 0;

                default:
                    printf("Geçersiz seçim! Lütfen tekrar deneyin.\n");
            }
        }

    return 0;
    }

*/