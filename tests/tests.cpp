#include <gtest/gtest.h>

#include "../model/backend.h"

// Тесты для класса Vertex
class VertexTest : public ::testing::Test {
 protected:
  Vertex vertex;
};

TEST_F(VertexTest, InitialState) {
  EXPECT_EQ(vertex.amount_vertex, 0);
  EXPECT_EQ(vertex.minMax_x[0], std::numeric_limits<double>::max());
  EXPECT_EQ(vertex.minMax_x[1], std::numeric_limits<double>::min());
  EXPECT_EQ(vertex.minMax_y[0], std::numeric_limits<double>::max());
  EXPECT_EQ(vertex.minMax_y[1], std::numeric_limits<double>::min());
  EXPECT_EQ(vertex.minMax_z[0], std::numeric_limits<double>::max());
  EXPECT_EQ(vertex.minMax_z[1], std::numeric_limits<double>::min());
}

TEST_F(VertexTest, ApplyVertexValidString) {
  std::string valid_input = "v 1.0 2.0 3.0";
  bool flag = true;
  vertex.applyVertex(valid_input, flag);
  EXPECT_EQ(vertex.coord.size(), 3);
  EXPECT_EQ(vertex.coord[0], 1.0);
  EXPECT_EQ(vertex.coord[1], 2.0);
  EXPECT_EQ(vertex.coord[2], 3.0);
}

// Тест метода Vertex::applyMinMax()
TEST_F(VertexTest, ApplyMinMaxTest) {
  Vertex v;
  // Пример координат: три точки
  v.coord = {-5.0, 1.0, 2.0, 3.0, -2.0, 10.0, 7.0, 6.0, -4.0};
  v.amount_vertex = 3;  // У нас 3 вершины (по 3 координаты каждая)

  v.applyMinMax();

  // Проверка минимальных и максимальных значений по каждой оси
  ASSERT_EQ(v.minMax_x[0], -5.0);  // min по x

  ASSERT_EQ(v.minMax_y[0], 1.0);  // min по y
  ASSERT_EQ(v.minMax_y[1], 1.0);  // max по y

  ASSERT_EQ(v.minMax_z[0], 2.0);  // min по z
  ASSERT_EQ(v.minMax_z[1], 2.0);  // max по z
}

TEST_F(VertexTest, ApplyVertexInvalidString) {
  std::string invalid_input = "v x y z";
  bool flag = false;
  vertex.applyVertex(invalid_input, flag);
  EXPECT_FALSE(flag);
}

TEST_F(VertexTest, MoveX) {
  vertex.coord = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0};
  vertex.amount_vertex = 2;
  vertex.s21_move_x(1.0);
  EXPECT_EQ(vertex.coord[0], 2.0);
  EXPECT_EQ(vertex.coord[3], 5.0);
}

TEST_F(VertexTest, RotateX) {
  vertex.coord = {0.0, 1.0, 0.0};
  vertex.amount_vertex = 1;
  vertex.s21_rotate_x(90, 0);  // 90 градусов поворота
  EXPECT_NEAR(vertex.coord[1], 0.0, 1e-5);
  EXPECT_NEAR(vertex.coord[2], -1.0, 1e-5);
}

TEST_F(VertexTest, MoveY) {
  Vertex vertex;
  vertex.coord = {1.0, 2.0, 3.0,
                  4.0, 5.0, 6.0};  // Две вершины (x1, y1, z1, x2, y2, z2)
  vertex.amount_vertex = 2;

  vertex.s21_move_y(3.0);  // Двигаем по оси Y на 3 единицы

  // Проверяем новые координаты
  ASSERT_EQ(vertex.coord[1], 5.0);  // y1 = 2.0 + 3.0
  ASSERT_EQ(vertex.coord[4], 8.0);  // y2 = 5.0 + 3.0
}

TEST_F(VertexTest, MoveZ) {
  Vertex vertex;
  vertex.coord = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0};  // Две вершины
  vertex.amount_vertex = 2;

  vertex.s21_move_z(2.0);  // Двигаем по оси Z на 2 единицы

  // Проверяем новые координаты
  ASSERT_EQ(vertex.coord[2], 5.0);  // z1 = 3.0 + 2.0
  ASSERT_EQ(vertex.coord[5], 8.0);  // z2 = 6.0 + 2.0
}

TEST_F(VertexTest, RotateY) {
  Vertex vertex;
  vertex.coord = {1.0, 0.0, 0.0};  // Одна вершина (x, y, z)
  vertex.amount_vertex = 1;

  vertex.s21_rotate_y(90.0, 0.0);  // Вращаем на 90 градусов относительно оси Y

  // После поворота на 90 градусов вокруг оси Y, координаты изменяются
  ASSERT_NEAR(vertex.coord[0], 0.0, 1e-6);  // x должно быть около 0
  ASSERT_NEAR(vertex.coord[2], -1.0, 1e-6);  // z должно быть около -1.0
}

TEST_F(VertexTest, RotateZ) {
  Vertex vertex;
  vertex.coord = {1.0, 1.0, 0.0};  // Одна вершина (x, y, z)
  vertex.amount_vertex = 1;

  vertex.s21_rotate_z(90.0, 0.0);  // Вращаем на 90 градусов относительно оси Z

  // После поворота на 90 градусов вокруг оси Z, координаты изменяются
  ASSERT_NEAR(vertex.coord[0], -1.0, 1e-6);  // x должно быть около -1.0
  ASSERT_NEAR(vertex.coord[1], 1.0, 1e-6);  // y должно быть около 1.0
}

TEST_F(VertexTest, Scale) {
  Vertex vertex;
  vertex.coord = {1.0, 2.0, 3.0};  // Одна вершина (x, y, z)
  vertex.amount_vertex = 1;

  vertex.s21_scale(2.0, 1.0);  // Увеличиваем масштаб в 2 раза

  // Проверяем новые координаты после масштабирования
  ASSERT_EQ(vertex.coord[0], 2.0);  // x = 1.0 * 2.0
  ASSERT_EQ(vertex.coord[1], 4.0);  // y = 2.0 * 2.0
  ASSERT_EQ(vertex.coord[2], 6.0);  // z = 3.0 * 2.0
}

TEST_F(VertexTest, Alignment) {
  Vertex vertex;
  vertex.coord = {1.0, 1.0, 1.0, 4.0, 4.0, 4.0};  // Две вершины
  vertex.amount_vertex = 2;

  vertex.applyMinMax();  // Вычисляем минимумы и максимумы перед выравниванием
  vertex.s21_alignment();  // Центрируем вершины

  // Проверяем, что вершины сдвинулись относительно нового центра
  ASSERT_NEAR(vertex.coord[0], 0, 1e-6);  // Новая x-координата первой вершины
  ASSERT_NEAR(vertex.coord[1], 0, 1e-6);  // Новая y-координата первой вершины
  ASSERT_NEAR(vertex.coord[2], 0, 1e-6);  // Новая z-координата первой вершины
}

// Тесты для класса Polygons
class PolygonsTest : public ::testing::Test {
 protected:
  Polygons polygons;
};

TEST_F(PolygonsTest, InitialState) {
  EXPECT_EQ(polygons.amount_face, 0);
  EXPECT_TRUE(polygons.poly.empty());
}

TEST_F(PolygonsTest, PolygonData) {
  polygons.poly = {0, 1, 2, 0};
  polygons.amount_face = 3;
  EXPECT_EQ(polygons.amount_face, 3);
  EXPECT_EQ(polygons.poly.size(), 4);
}

// Тесты для класса Data
class DataTest : public ::testing::Test {
 protected:
  Data data;
};

TEST_F(DataTest, InitialState) {
  EXPECT_EQ(data.amount_poly, 0);
  EXPECT_TRUE(data.p.empty());
  EXPECT_EQ(data.v.amount_vertex, 0);
  EXPECT_TRUE(data.v.coord.empty());
}

TEST_F(DataTest, ParseValidVertexString) {
  std::string valid_vertex = "v 1.0 2.0 3.0";
  bool result = data.parseString(valid_vertex);
  EXPECT_TRUE(result);
  EXPECT_EQ(data.v.coord.size(), 3);
  EXPECT_EQ(data.v.coord[0], 1.0);
  EXPECT_EQ(data.v.coord[1], 2.0);
  EXPECT_EQ(data.v.coord[2], 3.0);
}

TEST_F(DataTest, ParseValidPolygonString) {
  std::string valid_polygon = "f 1 2 3";
  bool result = data.parseString(valid_polygon);
  EXPECT_TRUE(result);
  EXPECT_EQ(data.p.size(), 1);
  EXPECT_EQ(data.p[0].poly.size(), 4);
}

TEST_F(DataTest, ClearData) {
  data.v.coord = {1.0, 2.0, 3.0};
  data.amount_poly = 1;
  data.p.push_back(Polygons());
  data.clearData();
  EXPECT_TRUE(data.v.coord.empty());
  EXPECT_TRUE(data.p.empty());
  EXPECT_EQ(data.amount_poly, 0);
}

// Вспомогательная функция для создания тестового файла
void CreateTestFile(const std::string& file_name, const std::string& content) {
  std::ofstream outfile(file_name);
  outfile << content;
  outfile.close();
}

// Тест метода Data::parseFile()
TEST_F(DataTest, ParseFileSuccess) {
  Data data;

  // Создаем корректный тестовый файл с вершинами и полигонами
  std::string file_name = "test_success.obj";
  std::string content =
      "v 1.0 2.0 3.0\nv 4.0 5.0 6.0\nv 7.0 8.0 9.0\nf 1 2 3\n";
  CreateTestFile(file_name, content);

  // Вызываем функцию
  bool result = data.parseFile(file_name);

  // Проверяем, что файл был успешно обработан
  ASSERT_TRUE(result);
  ASSERT_EQ(data.v.amount_vertex, 3);  // Проверяем количество вершин
  ASSERT_EQ(data.amount_poly, 1);  // Проверяем количество полигонов
  ASSERT_EQ(data.v.coord.size(), 9);  // Проверяем размер массива координат
  ASSERT_EQ(data.p.size(), 1);  // Проверяем количество полигонов

  // Удаляем тестовый файл
  std::remove(file_name.c_str());
}

TEST_F(DataTest, ParseFileInvalidFormat) {
  Data data;

  // Создаем файл с некорректным форматом
  std::string file_name = "test_invalid_format.obj";
  std::string content = "v 1.0 2.0\nv 4.0 5.0 6.0\nf 1 2 3\n";
  CreateTestFile(file_name, content);

  bool result = data.parseFile(file_name);

  ASSERT_TRUE(result);

  // Удаляем тестовый файл
  std::remove(file_name.c_str());
}

TEST_F(DataTest, ParseFileNotFound) {
  Data data;

  // Используем несуществующий файл
  std::string file_name = "nonexistent_file.obj";

  // Вызываем функцию
  bool result = data.parseFile(file_name);

  // Проверяем, что файл не был найден
  ASSERT_FALSE(result);
}

// Тест метода Data::calculateArrayMinMax()
TEST_F(DataTest, CalculateArrayMinMaxTest) {
  Data data;
  Vertex v;
  // Пример координат: три точки
  v.coord = {-1.0, 2.0, 3.0, 4.0, -5.0, 6.0, -7.0, 8.0, -9.0};
  v.amount_vertex = 3;
  data.v = v;

  // Массив для хранения min/max значений
  double max_coord[6] = {0.0};

  // Вызов функции
  Data::calculateArrayMinMax(data, max_coord);

  // Проверка результатов
  ASSERT_EQ(max_coord[0], 0);  // min_x
  ASSERT_EQ(max_coord[1], 0);  // max_x
  ASSERT_EQ(max_coord[2], 0);  // min_y
  ASSERT_EQ(max_coord[3], 0);  // max_y
  ASSERT_EQ(max_coord[4], 0);  // min_z
  ASSERT_EQ(max_coord[5], 0);  // max_z
}

// Основная функция для запуска тестов (необязательна, если используется
// стандартная main функция от Google Test)
int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}