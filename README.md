# 🧵 C++ Multithreaded Thread Pool  
Modern C++17 ile yazılmış, hafif, verimli ve genişletilebilir bir **multithreaded thread pool** yapısı.

<p align="left">
  <img src="https://img.shields.io/badge/C++-17-blue.svg">
  <img src="https://img.shields.io/badge/CMake-Build System-informational">
  <img src="https://github.com/ardaburakakin/cpp-threadpool/actions/workflows/build.yml/badge.svg">
  <img src="https://img.shields.io/badge/Platform-Windows%20%7C%20Linux%20%7C%20macOS-green">
</p>

Bu proje;

✔ Modern C++ concurrency  
✔ std::thread, std::mutex, condition_variable  
✔ Thread-safe message queue  
✔ std::future + packaged_task  
✔ Clean API design  
✔ RAII tabanlı otomatik thread yönetimi  

gibi alanlarda profesyonel C++ yetkinliğini göstermek için hazırlanmıştır.

---

## 🚀 Özellikler

- **Asenkron görev yürütme (async task scheduling)**  
- **Thread-safe iş kuyruğu (producer-consumer model)**  
- **Otomatik thread yaşam döngüsü yönetimi (RAII)**  
- **Temiz API tasarımı (`pool.submit(...)`)**  
- **Kolay genişletilebilir mimari**

---

## 📌 Örnek Kullanım

```cpp
ThreadPool pool(4);

auto result = pool.submit([] {
    std::this_thread::sleep_for(std::chrono::milliseconds(200));
    return 42;
});

std::cout << "Sonuç: " << result.get() << std::endl;
```

---

## 📂 Proje Yapısı

```
cpp-threadpool/
│
├── src/
│   ├── ThreadPool.h
│   ├── ThreadPool.cpp
│   ├── ThreadSafeQueue.h
│   └── main.cpp
│
├── CMakeLists.txt
├── README.md
├── LICENSE
└── CONTRIBUTING.md
```

---

## 🛠 Derleme Talimatı

### 1) Build klasörü oluştur
```bash
cmake -S . -B build
```

### 2) Derle
```bash
cmake --build build --config Debug
```

### 3) Çalıştır
```bash
./build/Debug/cpp_threadpool.exe
```

---

## 🧠 Teknik Mimari

### 1️⃣ ThreadSafeQueue  
- Mutex + condition variable ile korunur  
- Push ve pop işlemleri bloklanır  
- Üretici–tüketici (producer-consumer) modeli uygulanır  

### 2️⃣ ThreadPool  
- Başlatılırken N adet worker thread oluşturur  
- submit() → packaged_task → future mekanizması  
- Boş task = thread kapanma sinyali  

### 3️⃣ Task Scheduling  
- Görevler “lambda”, “callable obj”, “free function”… olabilir  
- Sonuçlar future ile alınır  

---

## 📈 Yol Haritası

- [ ] Öncelikli iş kuyruğu (priority queue)  
- [ ] Work stealing (çok çekirdek performansı)  
- [ ] Lock-free queue  
- [ ] Benchmark sonuçları  
- [ ] Linux/macOS CI ekleme  

---

## 📜 Lisans  
MIT lisansı (LICENSE dosyasında).

---

## 👨‍💻 Geliştirici  
**Arda Burak Akın**  
C++ • Multithreading • System Programming • Low-level Design  
