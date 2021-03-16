# 📻 Arduino ile Walkie-Talkie(Telsiz) Projesi

&emsp;Bu projede walkie-talkie yani bas-konuş özellikli telsiz yapımını, gerekli malzemeleri, kodları ve benim nasıl yaptığımı, yapamadığımı öğreneceksiniz.

> &emsp;Bu projenin videolu anlatımı ve testlerini aşağıdaki videodan izleyebilirsiniz.\
[▶️ Arduino ile Walkie-Talkie(Telsiz) Yapımı ve Testleri](https://www.youtube.com/channel/UCcg8zjG1kt-6sRfb4ajHWXQ)


![Telsizin Ön Yüzü](/images/perti-on.png)

# 🛠️ Kullanılan Malzemeler

Projede kullandığım malzemeleri, internetten aldığım sitelerden siz de alabilirsiniz.


> ***⚠️ Ürünlerin linkleri isimlerinde bulunuyor.***

- 2 adet **[Arduino Nano](https://www.direnc.net/arduino-nano-usb-chip-ch340-usb-kablo-dahil)**
    - Boyutundan ötürü ***`Nano`*** tercih ettim. Uno, Mega veya Nano kullanmak size kalmış.
    - Mega kullanıcaksanız bağlantılarda birkaç değişiklik oluyor unutmayın! (Anlatımda bundan bahsedicem.)
    
- 2 adet **[nRF24L01 PA LNA 2.4GHz Alıcı - Verici Modül](https://www.f1depo.com/Nrf24l01-Pa-Lna-24-ghz,PR-978.html)**
    - Antenli versiyonunu kullandım.
    - İki versiyonun da bağlantıları aynı.
    - Antensiz versiyonu açık alanda ort. 100m, kapalı alanda ort. 10-20m mesafede çalışıyormuş(!)(Söylenene göre...)
    - Antenli versiyonu ise ort. 10 kat artıyor. (Mesafe testinin videosu [*🔖 Yardım Aldığım Kaynaklar*](#-yardım-aldığım-kaynaklar)'da var)
    - VCC yi 3.3V'a bağlayın yoksa bozuluyor veya adaptör ile 5V da kullanın. Ben adaptörle 5V da kullandım.
    
- 2 adet **[nRF24L01 Wireless Modül Adaptörü](ttps://www.direnc.net/8-pin-nrf24l01-wireless-modul-adaptoru)**
    - Bu adaptör 5V ile çalışmayı sağlıyor.
    - Antenli yada antensiz olsun ikisinde de kullanmanızı öneririm.
    - Paraziti de azaltıyormuş(!)
    
- 2 adet **[MAX4466 Elektret Mikrofon](https://www.f1depo.com/urun/gy-max4466-elektret-mikrofon-amplifikatoru-max446)**
    - 5V veya 3.3V da kullanabilirsiniz ama 3.3V da daha temiz ses elde ettim.
    
- 2 adet **[8R 0.5W 83DB 36x5mm Hoparlör](https://www.direnc.net/8r-05w-83db-36x5mm-hoparlor)**
    - Arduino'nun besleyebileceği boyuta hoparlörlerin de çalışacağını düşünüyorum.

- 2 adet **[Buton](https://www.direnc.net/6x6-8-5mm-tach-buton-4-bacak)**
    - Benim kullandığım butonun tuş kısmı biraz uzun ve çapı küçük.
    - Uzun süre kullanımlarda daha geniş boyutlarda buton daha rahat kullanımı olabilir.
    - 2 bacaklı herhangi buton da çalışacakdır.
    
- 2 adet **[10K Direnç](https://www.direnc.net/10k-14w-direnc)** (*Kahve-Siyah-Turuncu-Altın*)

- **Jumper Kablo** (*[Dişi - Erkek](https://www.direnc.net/40-adet-disi-erkek-jumper-20cm), [Erkek- Erkek](https://www.f1depo.com/40-pin-Erkek-Erkek-200mm-20cm-Jumper-Kablo,PR-695.html)*)

- 2 adet **Breadboard**
    - Devreyi kurup test etmek için kullandım.
    - Çeşit olsun diye farklı boyutlarda aldım. Orta boy, devre için yeterli alanı sağlıyor.
    - [Büyük Boy Breadboard](https://www.direnc.net/tekli-breadboard)
    - [Orta Boy Breadboard](https://www.direnc.net/breadboard-mini-yapiskanli)
    
- **[Pertinaks](https://www.f1depo.com/Delikli-Plaket-12x18-cm-Pertinaks,PR-2256.html)**
    - Breadboard üzerindeki testlerden sonra devreyi lehim ile sabit halde kullanmak için aldım.
    - Jumper kablolar ortada cirit atmamış oluyor.
    - İlk pertinaks alma ve kullanma deneyimim olacağından dolayı riske atmayıp 2 adet almıştım ama 1 tanesi(12x18cm) yetti.
    
- **[Havya](https://www.f1depo.com/urun/40w-kalem-havya-tse-onaylidir)**
    - Eğer pertinaks üzerine sabitlemeyecekseniz sadece hoparlör kablolarını lehimlemek için kullandım.
    - İnce havya ucu ile lehim daha kolay yapılabilirdi bence.
    
- **[Lehim Teli](https://www.f1depo.com/urun/pinax-tup-lehim-teli-1-2mm)**
    - 1.2mm kalınlığında tel kullandım ama daha ince (0.75mm vb.) tel ile lehim işlemi daha kolay olabilirdi.
    
- **Silikon Tabancası**
    - Devrede hareketli parçaları sabitlemek ve devrelere teması engellemek için dışını balonlu naylonla(patlatılan poşetler) kaplamak için kullandım.
    - **Örn.** Hoparlör sarkık durmaması için
    
- **Kablo Soymak için Aletler**
    - Kablo soyma pensesi yerine yan keski ve pense kullandım ama soyma pensesi olsa daha kolay olurdu.

---

# 📥 Kütüphanelerin ve Kodların İndirilmesi

*RF24*, *RF24Audio* kütüphanelerini ve telsiz için gereken kodları aşağıdaki bağlantılardan indirin.

**RF24:** [github.com/nRF24/RF24](https://github.com/nRF24/RF24)\
**RF24Audio:** [github.com/nRF24/RF24Audio](https://github.com/nRF24/RF24Audio)\
**Gerekli Kodlar:** [github.com/ZekeriyaAY/Arduino-Walkie-Talkie](https://github.com/ZekeriyaAY/Arduino-Walkie-Talkie)

---

# 📤 Kütüphanelerin IDE'ye Eklenmesi

İndirilen `.zip` dosyalarını aşağıdaki yol ile ekleyin.
*Sadece RF24 ve RF24Audio dosyaları kütüphane dosyalarıdır.*

```arduino
Arduino IDE > Taslak > library ekle > .ZIP Kitaplığı Ekle...
```

---

# 📤 Kodların Arduino'ya Yüklenmesi
Bu aşamaya şuan ihtiyaç yok ancak devre bağlantılarını yaptıktan sonra kodları burada anlatıldığı gibi yüklemeniz için eklendi.

- İndirilen `Arduino-Walkie-Talkie.zip`  dosyasının içindeki `.ino` uzantılı arduino kodunu IDE ile açın.
- Arduino'yu bilgisayara takın.

```arduino
Araçlar > Kart //Kullandığınız Arduino türünü seçin
Araçlar > Port //Kartın takılı olduğu portu seçin
```

> Portlarda kartınız gözükmüyorsa -> [CH340 çipli klon arduino sürücüleri nasıl yüklenir?](https://maker.robotistan.com/arduino-uno-suruculeri-nasil-yuklenir-ch340-cipli-klon/)

Doğru kartı ve portu seçtiğinizden eminseniz iki Arduino'ya da kodları yükleyebilirsiniz.

> Yükleme sırasında sorun çıktı ise 
> ```c
> Araçlar > İşlemci  //Diğer seçeneklere bi' bak
> Ben de ATmega328P(Old Bootloader) seçtiğimde sorun geçmişti.
> ```
---

# 🗺️ Devre Kurulum ve Test Edilmesi

Sıra aldığımız malzemeleri birleştirip test etmeye geldi.

## 📡nRF24L01 Bağlantısı ve Testi

> nRF24L01 modülü ve kullanacağımız adaptör ile nRF24L01 bağlantıları aşağıda bulunuyor.
>
>![nRF24L01 Modülün Pin Çıkışları (Resim 1)](/images/nRF24L01-pinout.png#center)

![nRF24L01 Modül Adaptörü (Resim 2)](/images/nRF24L01-adaptor.jpeg#center)

> Adaptör kullanmadan yapılan bağlantı aşağıda gösteriliyor. Adaptör kullanarak yapılan bağlantıda tek değişiklik `VCC`'yi `3.3V` yerine `5V`'a bağlamanız.
> - Boş olan pin, kullanılmayan `IRQ` pini.
>
> ![Modülün Adaptörsüz Bağlantısı (Resim 3)](/images/nRF24L01-adaptor-sema.png#center)



Aşağıdaki pin dizilimleri *Nano/Uno* içindir. *Mega* için farklı pinler kullanılıyor. [🔖 **Yardım Aldığım Kaynaklar**](#-yardım-aldığım-kaynaklar)'da o bağlantıları bulabilirsiniz.

|            |     |        |    |     |     |      |      |
|------------|-----|--------|----|-----|-----|------|------|
|**nRF24L01**| GND |   VCC  | CE | CSN | SCK | MOSI | MISO |
| **Arduino**| GND | 3.3/5V | D7 |  D8 | D13 |  D11 |  D12 |


> `Arduino-Walkie-Talkie-main.zip` dosyasındaki `alici.ino` kodunu bir Arduino'ya, `verici.ino` kodunu diğer Arduino'ya yükleyin.

İki kodu da farklı Arduinolara yükledikten sonra alıcı kodunu yüklediğiniz Arduino'nun "**Seri Port Ekranı**" nda "**Hello Ardu**" yazısını görüyorsanız bağlantılar doğrudur demektir.

## 🔊 Hoparlör Bağlantısı ve Testi

![Hoparlör Bağlantı Şeması (Resim 4)](/images/hoparlor-sema.png#center)

Hoparlör üzerinde kırmızı kablo(+) D10 pinine , siyah kablo(-) GND pinine bağladım.

> `Arduino-Walkie-Talkie-main.zip` dosyasındaki `hoparlor.ino` kodunu Arduino'ya yükleyip hoparlör bağlantılarını melodi sesleriyle test edebilirsiniz.

## 🔘 Buton Bağlantısı ve Testi

![Buton Bağlantı Şeması (Resim 5)](/images/buton-sema.png#center)

> `Arduino-Walkie-Talkie-main.zip` dosyasındaki `buton.ino` kodunu Arduino'ya yükleyin.

Kodu yükledikten sonra "**Seri Port Ekranı**" nda butona bastığınızda sayaç sayıları artıyorsa sıradaki ve son bağlantıya geçebilirsiniz.

## 🎤 Mikrofon Bağlantısı ve Testi

![Mikrofon Bağlantı Şeması (Resim 6)](/images/mik-sema.png#center)

5V'a da bağlayabilirsiniz. Ancak 3.3V da daha temiz ses elde ettiğim için 3.3V kullandım.

> `Arduino-Walkie-Talkie-main.zip` dosyasındaki `Mikrofon.ino` kodunu Arduino'ya yükleyin.

Kodu çalıştırdıktan sonra "**Seri Port Ekranı**" nda mikrofona konuştuğunuz zaman Volt değerlerini göreceksiniz. Eğer değişim olmuyorsa bağlantıları kontrol edin.

## 🗺️ Tüm Bağlantı Şeması

![Tüm Bağlantı Şeması (Resim 7)](/images/son-sema.png#center)

Resim 7'de devrenin son hali var. Şemaları çizdiğimiz programda nRF24L01 antenli versiyonu veya adaptörü olmadığı için şemada antensiz ve adaptörsüz halini görüyorsunuz. Bağlantılarda herhangi bir farklılık yok.

---

# 📤 Ana Kodun Arduino'ya Yüklenmesi

İndirilen `Arduino-Walkie-Talkie-main.zip`  dosyasının içindeki `Walkie-Talkie-Kod.ino` kodu iki Arduino'ya [📤 Kodların Arduino'ya Yüklenmesi](#-kodların-arduinoya-yüklenmesi)nde anlatıldığı gibi yükleyin.

Sorunsuz yüklendiyse butona basıp konuşmaya başlayabilirsiniz.

---

# 📦 Lehim ile Sabit Devre Kurulumu

Devremizi breadboard üzerine kurduk, kodları yükleyip çalıştırdık. Sırada lehim ile pertinaks üzerine sabit devreyi kurma aşamasına geldik.

>Bu aşama zorunlu değildir. İsterseniz breadboard üzerinde kullanabilirsiniz ancak pertinaks üzerinde kablo karmaşası olmadan daha kullanışlı olduğu için bu aşamayı yaptım.
Ayrıca pertinaks üzerinde sabit devrede mikrofonda gürültü daha çok azaldı. Sanırım jumper kablolar daha az, daha kısa olduğu için oldu.

![Devrenin Önden Görünümü (Resim 8)](/images/perti-on.png#center)

![Devrenin Arkadan Antensiz Görünümü (Resim 9)](/images/perti-arka-antensiz.png#center)

![Devrenin Arkadan Antenli Görünümü (Resim 10)](/images/perti-arka-antenli.png#center)

>Alıcı-verici modülü sabitlemek için altına sıcak silikon sıktım. Yoksa hareket ettiğinde pinlerde temassızlık oluyor ve telsiz bağlantıları kesiliyordu.

![Devrenin Yandan Görünümü (Resim 11)](/images/perti-yan.jpeg#center)

>Devrenin arkasındaki pinlere dokununca devre bozulabiliyor. Bu yüzden arkasına ve önüne patlatılan poşetlerden kesip sıcak silikonla yapıştırdım. Böylece devrelere temas etmemiş oluyoruz. 

![Devrenin Arkadan Paketli Görünümü (Resim 12)](/images/son-arka-tek.png#center)

![Telsizlerin Önden Görünümü (Resim 13))](/images/son-on.jpeg#center)

![Telsizlerin Arkadan Görünümü (Resim 14)](/images/son-arka.jpeg#center)


>Telsizin testlerini aşağıdaki linkten izleyebilirsiniz.\
[▶️ **Arduino ile Walkie-Talkie(Telsiz) Yapımı**](https://www.youtube.com/channel/UCcg8zjG1kt-6sRfb4ajHWXQ)

---

# 🔖 Yardım Aldığım Kaynaklar

- nRF24L01 Modülü ile İlgili
    - [hayaletveyap.com/arduino-ile-nrf24l01-kablosuz-rf-modul-kullanimi/](https://hayaletveyap.com/arduino-ile-nrf24l01-kablosuz-rf-modul-kullanimi/)
    - [lastminuteengineers.com/nrf24l01-arduino-wireless-communication/](https://lastminuteengineers.com/nrf24l01-arduino-wireless-communication/)

- [nRF24L01 Antenli ve Antensiz Menzil Testi Videosu](https://www.youtube.com/watch?v=2tfa9i0bsX8&ab_channel=Merakl%C4%B1Maymun)

- [Walkie-Talkie Yapan En Detaylı Kaynak Olabilir (İngilizce)](https://www.instructables.com/id/Wristwatch-Walkie-Talkie/)

- [Walkie-Talkie Yapan Türkçe Kaynak](https://ugrdmr.wordpress.com/2018/07/22/arduino-telsiz-walkie-talkie/)

---

# 🖋️Sonuç Nasıl Oldu?

Sonuçtan büyük ölçekte memnunum.
Birkaç tecrübe edindim.

- Pertinaks üzerine lehimlerken Arduino'yu direk lehimledim. Bunu yapmak yerine *dişi pin header* lehimleyip Arduino'yu bu headerlara takmak daha iyi olur. Böylece gerektiğinde Arduino'yu kolayca çıkartılıp yenisi takılabilir veya başka şeylerde kullanılabilir.
- İlk uzun lehim deneyimim olduğundan dolayımı bilmiyorum ama *daha ince lehim teli*, d*aha ince havya ucu* ve *lehim pastası* kullansam lehim işlemleri daha kolay olabilirdi.
- Kabloları soymak için *kablo soyma pensesi*  kullanmak daha kısa sürmesine ve daha düzenli olmasına neden olabilirdi. Pense ve yan keski kullanarak biraz zor oldu.
- Telsiz çalışırken iki taraf da butona basılı tutup konuşmaya çalışınca iki taraf da duymadığı gibi bug'a girmesine neden oluyor. Böyle durumlarda Arduino üzerindeki butona basıp kodların tekrar çalıştırılmasını sağlayarak bug sorunu o anlık çözebiliyoruz. Bir taraf konuşurken diğer taraf da dinlemesini bilmeli yani 🙃

---

**📎*Beni Aşağıdan Takip Ederek ve Abone Olarak Destekleyebilirsiniz***

[ZekeriyaAY - Github](https://github.com/ZekeriyaAY)

[LeadScript - Youtube](https://www.youtube.com/channel/UCcg8zjG1kt-6sRfb4ajHWXQ)


