// class Name_Z {
//     static int GetID(const char* a1, unsigned long a2);
// };

// int Name_Z::GetID(const char* a1, unsigned long a2) {
//     while (*a1)
//     {
//         a2 = (Crc32Tab[(a2 ^ g_ChartoLower[*(a1)]) & 0xFF]) ^ (a2 >> 8);
//         a1++;
//     }
//     return a2;
// }