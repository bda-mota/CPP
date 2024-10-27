#include "../includes/Bureaucrat.hpp"
#include "../includes/AForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"

int main() {
    try {
        // Criar um Bureaucrat
        Bureaucrat roger("Roger", 50);
        std::cout << roger << std::endl;

        // Criar formulários
        ShrubberyCreationForm shrubForm("home");
        RobotomyRequestForm robotForm("target1");
        PresidentialPardonForm pardonForm("target2");

        std::cout << shrubForm << std::endl;
        std::cout << robotForm << std::endl;
        std::cout << pardonForm << std::endl;

        // Testar assinatura de formulários
        std::cout << "Signing forms..." << std::endl;
        roger.signForm(shrubForm);  // Deveria falhar, grade muito baixa
        roger.signForm(robotForm);   // Deveria falhar, grade muito baixa
        roger.signForm(pardonForm);  // Deveria falhar, grade muito baixa

        // Aumentar o grau do Bureaucrat para assinar os formulários
        roger.upGrade();
        roger.upGrade();  // Grau agora é 48
        roger.signForm(robotForm); // Agora pode assinar
        roger.signForm(shrubForm);  // Deveria falhar, ainda não é 145
        roger.signForm(pardonForm);  // Deveria falhar, ainda não é 25

        // Aumentar o grau novamente
        for (int i = 0; i < 10; ++i) { // Aumentando para 38
            roger.upGrade();
        }
        std::cout << roger << std::endl;

        // Testar assinatura novamente
        roger.signForm(shrubForm); // Agora pode assinar
        roger.signForm(pardonForm); // Agora pode assinar

        // Executar formulários
        std::cout << "Executing forms..." << std::endl;
        roger.executeForm(shrubForm); // Deveria criar um arquivo
        roger.executeForm(robotForm);  // Pode ter sucesso ou falhar
        roger.executeForm(pardonForm); // Deveria informar que o alvo foi perdoado

    } catch (const std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    // Testar exceções com graus inválidos
    try {
        Bureaucrat lowBureaucrat("LowBob", 151); // Deve falhar ao criar
    } catch (const std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    ShrubberyCreationForm shrubForm("home"); // Inicializa o formulário para "home"
    // Testar se a execução de um formulário não assinado falha
    try {
        Bureaucrat anotherBureaucrat("Alice", 30);
        anotherBureaucrat.executeForm(shrubForm); // Deve falhar, não assinado
    } catch (const std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}