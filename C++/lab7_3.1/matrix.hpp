#ifndef MATRIX
#define MATRIX

#include <sstream>
#include <limits>
#include <vector>
#include <stdexcept>
#include <functional>
#include <algorithm> 
#include <numeric>
#include <string>

class Matrix
{
private:
    std::vector<std::vector<double>> matrix;
    int N, M;
    std::string name;
public:
    Matrix(std::vector<std::vector<double>>& m)
    {
        M = m.size();
        N = m[0].size();

        matrix = m;
    }

    Matrix() {}

    Matrix E() const
    {
        std::vector<std::vector<double>> e(N);
        for (int i = 0; i < N; ++i)
        {
            std::vector<double> line(N);
            line[i] = 1;
            e[i] = line;
        }
        
        return Matrix(e);
    }

    Matrix operator+(Matrix& other) const
    {
        std::vector<std::vector<double>> result(M);

        if (other.N != N || other.M != M)
        {
            throw std::logic_error("Wrong arguments"); 
        }

        for (int i = 0; i < M; ++i)
        {
            std::vector<double> line (N);

            for (int j = 0; j < N; ++j)
            {
                line[j] = matrix[i][j] + other.matrix[i][j];
            }
            
            result[i] = line;
        }

        return Matrix(result);
    }
    Matrix operator-(Matrix& other) const
    {
        std::vector<std::vector<double>> result(M);

        if (other.N != N || other.M != M)
        {
            throw std::logic_error("Wrong arguments"); 
        }

        for (int i = 0; i < M; ++i)
        {
            std::vector<double> line (N);

            for (int j = 0; j < N; ++j)
            {
                line[j] = matrix[i][j] - other.matrix[i][j];
            }
            
            result[i] = line;
        }

        return Matrix(result);
    }
    void operator+=(Matrix& other)
    {
        for (int i = 0; i < M; ++i)
        {
            for (int j = 0; j < N; ++j)
            {
                matrix[i][j] += other.matrix[i][j];
            }
        }
    }
    void operator-=(Matrix& other)
    {
        for (int i = 0; i < M; ++i)
        {
            for (int j = 0; j < N; ++j)
            {
                matrix[i][j] -= other.matrix[i][j];
            }
        }
    }

    template<typename T>
    Matrix operator*(T other) const
    {
        std::vector<std::vector<double>> result(M);

        for (int i = 0; i < M; ++i)
        {
            for (int j = 0; j < N; ++j)
            {
                result[i].push_back(matrix[i][j] * other);
            }
        }

        return Matrix(result);
    }
    template<typename T>
    Matrix operator/(T other) const
    {
        std::vector<std::vector<double>> result(M);

        for (int i = 0; i < M; ++i)
        {
            for (int j = 0; j < N; ++j)
            {
                result[i].push_back(matrix[i][j] / other);
            }
        }

        return Matrix(result);
    }
    template<typename T>
    void operator*=(T other)
    {
        for (int i = 0; i < M; ++i)
        {
            for (int j = 0; j < N; ++j)
            {
                matrix[i][j] *= other;
            }
        }
    }
    template<typename T>
    void operator/=(T other)
    {
        for (int i = 0; i < M; ++i)
        {
            for (int j = 0; j < N; ++j)
            {
                matrix[i][j] /= other;
            }
        }
    }

    friend bool operator==(Matrix& first, Matrix& second)
    {
        if (first.M != second.M || first.M != second.M) return false;

        for (int i = 0; i < first.M; ++i)
        {
            for (int j = 0; j < first.N; ++j)
            {
                if (first.matrix[i][j] != second.matrix[i][j])
                {
                    return false;
                }
            }
        }

        return true;
    }

    double operator[](int m) const
    {
        if (M < m)
        {
            throw std::logic_error("Out of range"); 
        }
        m--;
        
        return std::accumulate(matrix[m].begin(), matrix[m].end(), 0);
    }
    double operator()(int n) const
    {
        if (N < n)
        {
            throw std::logic_error("Out of range"); 
        }
        n--;
        
        double sum(0);
        for (int i = 0; i < M; i++)
        {
            sum += matrix[i][n];
        }
        return sum;
    }

    double min() const
    {
        double min(std::numeric_limits<double>::max());

        for (int i = 0; i < M; ++i)
        {
            auto lineMin = *std::min_element(matrix[i].begin(), matrix[i].end());

            if (lineMin < min)
            {
                min = lineMin;
            }
        }

        return min;
    }
    double max() const
    {
        double max(std::numeric_limits<double>::min());

        for (int i = 0; i < M; ++i)
        {
            auto lineMax = *std::max_element(matrix[i].begin(), matrix[i].end());

            if (lineMax < max)
            {
                max = lineMax;
            }
        }

        return max;
    }

    friend Matrix mmult(Matrix first, Matrix second);

    friend Matrix pow(Matrix matrix, unsigned int n);

    friend std::ostream& operator<<(std::ostream& stream, Matrix matrix)
    {
        for (int i = 0; i < matrix.M; ++i)
        {
            for (int j = 0; j < matrix.N; ++j)
            {
                stream << matrix.matrix[i][j] << ' ';
            }
            
            stream << "\n";
        }
        
        return stream;
    }
};

Matrix mmult(Matrix first, Matrix second)
{
    if (first.N != second.M)
    {
        throw std::logic_error("Wrong arguments"); 
    }

    std::vector<std::vector<double>> result;
    
    for (int i = 0; i < first.M; ++i)
    {
        std::vector<double> line;

        for (int j = 0; j < second.N; ++j)
        {
            double buf(0);

            for (int k = 0; k < first.N; ++k)
            {
                buf += first.matrix[i][k] * second.matrix[k][j];
            }
                
            line.push_back(buf);
        }

        result.push_back(line);
    }
    
    return Matrix(result);
}

Matrix pow(Matrix matrix, unsigned int n)
{
    if (matrix.M != matrix.N)
    {
        throw std::logic_error("Wrong arguments"); 
    }
        
    if (n == 0)
    {
        return matrix.E();
    }

    if (n % 2)
    {
        return mmult(pow(matrix, n - 1), matrix);
    }
    else
    {
        Matrix buf = pow(matrix, n / 2);
        return mmult(buf, buf);
    }
}

#endif