🇹🇷 TR

Eğitim ve Araştırma Uygulamaları İçin VR Destekli Robotik Cerrahi Eğitim Platformu

Bu proje, sağlık bilimleri ve mühendislik eğitiminde kullanılan yüksek maliyetli robotik sistemlere erişilebilir bir alternatif oluşturmak amacıyla geliştirilmiş hibrit bir eğitim ve araştırma platformudur. Sistem; Sanal Gerçeklik (VR), yapay zekâ destekli görüntü işleme, kablosuz haberleşme ve 3B yazıcıyla üretilmiş robotik bir kolu tek bir ekosistemde bir araya getirmektedir.

Proje kapsamında Berlin Charité Hastanesi'nden elde edilen fotogrametrik tarama verileri kullanılarak gerçekçi bir ameliyathane ortamı oluşturulmuş ve Unity tabanlı VR simülasyonuna entegre edilmiştir. Simülasyon ortamı tamamen açık kaynaklı teknolojiler, açık veri kaynakları ve açık erişimli varlıklar kullanılarak geliştirilmiştir.

Fiziksel robot kol tasarımı, açık kaynaklı BCN3D Moveo platformu temel alınarak yeniden modellenmiş ve eğitim senaryosunun ihtiyaçlarına uygun şekilde optimize edilmiştir. Orijinal çok eksenli yapı sadeleştirilerek 3 serbestlik dereceli (3-DoF) bir mimariye dönüştürülmüş ve tamamen 3B yazıcı teknolojileri kullanılarak üretilmiştir.

Sistemde iki farklı veri akışı eş zamanlı olarak çalışmaktadır. Kullanıcının VR ortamında seçtiği cerrahi alet bilgisi, XBee tabanlı kablosuz haberleşme altyapısı üzerinden fiziksel sisteme aktarılır. Aynı anda Grove Vision AI ve YOLOv8 tabanlı görüntü işleme sistemi çalışma alanındaki cerrahi aletleri gerçek zamanlı olarak algılar ve konum bilgilerini üretir. Merkezi kontrol birimi, VR tarafından gönderilen hedef nesne bilgisi ile yapay zekâ sisteminden gelen konum verilerini eşleştirerek robot kolun doğru nesneyi kavramasını ve doğru hedef noktaya taşımasını sağlar.

Bu yaklaşım sayesinde proje yalnızca bir VR simülasyonu veya yalnızca bir robot kol çalışması olmaktan çıkarak; sanal ortam, yapay zekâ algılama sistemi ve fiziksel robotu gerçek zamanlı olarak birleştiren bir Dijital İkiz (Digital Twin) platformuna dönüşmektedir.

Kullanılan Başlıca Teknolojiler

- Unity 6
- OpenXR
- YOLOv8
- Grove Vision AI V2
- XBee (IEEE 802.15.4)
- Arduino Mega
- ESP32
- BCN3D Moveo (Open Source Reference Architecture)
- Fusion 360
- 3D Printing Technologies

Proje Ekibi

Ayşe Sena ŞAHİN

Ceren Sena ALTUĞ

Nehir DÖLER

Nehir ERDEN

Sıla Nur SÖNMEZ

Yiğit Kemal YEŞİLTAŞ


Danışmanlar

Prof. Dr. Sedat NAZLIBİLEK

Prof. Dr. Ziya TELATAR

Dr. Öğr. Üyesi Onur KOÇAK


Not

Bu proje geliştirilirken literatür araştırması, yazılım geliştirme, hata ayıklama, dokümantasyon ve teknik doğrulama süreçlerinin çeşitli aşamalarında yapay zekâ araçlarından destek alınmıştır.

--------------------------------------------------------------

🇬🇧 EN

VR-Assisted Robotic Surgical Training Platform for Educational and Research Applications

This project is a hybrid educational and research platform developed as an accessible alternative to high-cost robotic systems used in healthcare and engineering education. The system combines Virtual Reality (VR), AI-powered computer vision, wireless communication, and a 3D-printed robotic arm within a single integrated ecosystem.

A realistic operating room environment was reconstructed using photogrammetric data acquired from Berlin Charité Hospital and integrated into a Unity-based VR simulation. The virtual environment was developed entirely using open-source technologies, open datasets, and openly available digital assets.

The physical robotic arm was redesigned based on the open-source BCN3D Moveo platform and optimized for the educational objectives of the project. The original multi-axis architecture was simplified into a three-degree-of-freedom (3-DoF) robotic system and manufactured using additive manufacturing technologies.

The system operates through two simultaneous data streams. The surgical instrument selected by the user inside the VR environment is transmitted to the physical platform via an XBee-based wireless communication network. At the same time, a Grove Vision AI and YOLOv8-powered perception system continuously detects surgical instruments within the workspace and generates real-time positional data. The central control unit correlates the target object selected in VR with the position data provided by the AI vision system, enabling the robotic arm to identify, grasp, and transport the correct instrument to the designated destination.

By combining immersive VR interaction, AI-based perception, and physical robotic actuation, the project goes beyond a conventional simulation environment and evolves into a Digital Twin platform where virtual and physical systems operate synchronously in real time.

Key Features

- Photogrammetry-based Operating Room Reconstruction
- Virtual Reality Surgical Training Environment
- Digital Twin Architecture
- AI-Powered Object Detection and Localization
- Real-Time Wireless Communication
- Autonomous Instrument Identification and Handling
- Open-Source-Based Robotic System Design
- Low-Cost and Reproducible Educational Platform

Technologies

- Unity 6
- OpenXR
- YOLOv8
- Grove Vision AI V2
- XBee (IEEE 802.15.4)
- Arduino Mega
- ESP32
- BCN3D Moveo (Open-Source Reference Architecture)
- Fusion 360
- 3D Printing Technologies

Project Team

Ayşe Sena ŞAHİN

Ceren Sena ALTUĞ

Nehir DÖLER

Nehir ERDEN

Sıla Nur SÖNMEZ

Yiğit Kemal YEŞİLTAŞ

Supervisors

Prof. Dr. Sedat NAZLIBİLEK

Prof. Dr. Ziya TELATAR

Asst. Prof. Dr. Onur KOÇAK

Acknowledgement

This project was developed with support from various artificial intelligence tools during selected stages of literature review, software development, debugging, documentation, and technical validation.
