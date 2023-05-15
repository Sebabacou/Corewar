/*
** EPITECH PROJECT, 2023
** converse endian
** File description:
** conver big to little 
*/

int convertEndian(int value) {
    return ((value & 0xFF000000) >> 24) | ((value & 0x00FF0000) >> 8) \
| ((value & 0x0000FF00) << 8)  | ((value & 0x000000FF) << 24);
}