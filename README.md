# 🧵 C++ Multithreaded Thread Pool  
Modern C++ (C++17) ile yazılmış, hafif, temiz ve genişletilebilir bir **çok iş parçacıklı (multithreaded) thread pool** yapısı.

Bu proje;
✔ Modern C++ standardı  
✔ std::thread, std::mutex, std::condition_variable  
✔ Thread-safe queue  
✔ Packaged task + future  
✔ Asenkron görev yürütme (async task scheduling)  
✔ RAII tabanlı temiz kapanış  
gibi konularda yetkinliği göstermek için hazırlanmıştır.

---

## 🚀 Özellikler

- **Asenkron görev yürütme:**  
  Fonksiyonları thread pool’a gönder, sonuçları `std::future` ile al.

- **Thread-safe iş kuyruğu:**  
  Üretici-tüketici (producer/consumer) modeli uygulanmıştır.

- **Otomatik thread yönetimi:**  
  Havuz oluşturulur oluşturulmaz thread’ler başlar; program kapanırken temiz şekilde durur.

- **Modern C++ tasarımı:**  
  `std::invoke_result`, `std::packaged_task`, `std::function`, `move semantics`

- **Kolay kullanımlı API:**
  ```cpp
  pool.submit([] { return 42; });

📂 Proje Yapısı 
cpp-threadpool/
│
├── src/
│   ├── ThreadPool.h
│   ├── ThreadPool.cpp
│   ├── ThreadSafeQueue.h
│   └── main.cpp
│
├── CMakeLists.txt
└── README.md

🛠 Kurulum ve Çalıştırma
1. Build dizini oluştur
   cmake -S . -B build
2. Derle
   cmake --build build --config Debug
3. Çalıştır
   ./build/Debug/cpp_threadpool.exe

📌 Örnek Kullanım
ThreadPool pool(4);

auto result = pool.submit([] {
    std::this_thread::sleep_for(std::chrono::milliseconds(200));
    return 42;
});

std::cout << "Sonuç: " << result.get() << std::endl;

🧠 Teknik Mimari
🔸 1. ThreadSafeQueue

Thread-safe bir std::queue sarmalayıcıdır.
Mutex + condition variable ile senkronize edilir.

🔸 2. ThreadPool

Belirtilen sayıda worker thread oluşturur

Görevleri kuyruğa alır

Her thread worker_loop() içinde bekler

Boş (nullptr) bir iş gelince thread kapanır

🔸 3. Task Scheduling

Görevler std::packaged_task olarak tutulur;
sonuçlar std::future üzerinden alınır.

🎯 Öğrenilen / Gösterilen Yetkinlikler

Çok iş parçacıklı programlama (Multithreading)

Üretici–tüketici modeli

Senkronizasyon primitifleri
(std::mutex, std::condition_variable)

C++17 template metaprogramming (invoke_result)

Asenkron görev yönetimi

Thread-safe veri yapıları

Modern C++ API tasarımı

CMake proje organizasyonu
