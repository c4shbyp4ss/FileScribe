#ifndef SLICER_H
#define SLICER_H

/*
 * Divide um arquivo de texto em partes menores.
 *
 * @param input_path     caminho do arquivo de entrada
 * @param lines_per_part número de linhas por parte
 * @param output_dir     diretório onde as partes serão salvas
 * @return 0 em caso de sucesso, -1 em caso de erro
 */
int sliceFile(const char *input_path, int lines_per_part, const char *output_dir);

#endif /* SLICER_H */
