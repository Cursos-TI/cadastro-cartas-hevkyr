#include <stdio.h>

int main() {
    /* ===== Variáveis - Carta 1 ===== */
    char estado1[3];
    char codigo1[5];
    char nomeCidade1[50];
    unsigned long int populacao1;
    float area1;
    float pib1;
    int pontosTuristicos1;
    float densidadePopulacional1;
    float pibPerCapita1;
    float superPoder1;

    /* ===== Variáveis - Carta 2 ===== */
    char estado2[3];
    char codigo2[5];
    char nomeCidade2[50];
    unsigned long int populacao2;
    float area2;
    float pib2;
    int pontosTuristicos2;
    float densidadePopulacional2;
    float pibPerCapita2;
    float superPoder2;

    /* ===== Leitura - Carta 1 ===== */
    printf("=== Cadastro da Carta 1 ===\n");

    printf("Estado (letra): ");
    scanf("%s", estado1);

    printf("Código da carta: ");
    scanf("%s", codigo1);

    printf("Nome da cidade: ");
    scanf(" %[^\n]", nomeCidade1);

    printf("População: ");
    scanf("%lu", &populacao1);

    printf("Área (km²): ");
    scanf("%f", &area1);

    printf("PIB (bilhões de reais): ");
    scanf("%f", &pib1);

    printf("Número de pontos turísticos: ");
    scanf("%d", &pontosTuristicos1);

    /* ===== Leitura - Carta 2 ===== */
    printf("\n=== Cadastro da Carta 2 ===\n");

    printf("Estado (letra): ");
    scanf("%s", estado2);

    printf("Código da carta: ");
    scanf("%s", codigo2);

    printf("Nome da cidade: ");
    scanf(" %[^\n]", nomeCidade2);

    printf("População: ");
    scanf("%lu", &populacao2);

    printf("Área (km²): ");
    scanf("%f", &area2);

    printf("PIB (bilhões de reais): ");
    scanf("%f", &pib2);

    printf("Número de pontos turísticos: ");
    scanf("%d", &pontosTuristicos2);

    /* ===== Cálculos - Carta 1 ===== */
    densidadePopulacional1 = (float)populacao1 / area1;
    pibPerCapita1         = (pib1 * 1000000000.0f) / (float)populacao1;

    /*
     * Super Poder = população + área + PIB (em reais) + pontos turísticos
     *             + PIB per capita + (1 / densidade)
     * O inverso da densidade faz com que cidades menos densas tenham mais "poder".
     * Casts explícitos garantem que a soma não perca precisão.
     */
    superPoder1 = (float)populacao1
                + area1
                + (pib1 * 1000000000.0f)
                + (float)pontosTuristicos1
                + pibPerCapita1
                + (1.0f / densidadePopulacional1);

    /* ===== Cálculos - Carta 2 ===== */
    densidadePopulacional2 = (float)populacao2 / area2;
    pibPerCapita2         = (pib2 * 1000000000.0f) / (float)populacao2;

    superPoder2 = (float)populacao2
                + area2
                + (pib2 * 1000000000.0f)
                + (float)pontosTuristicos2
                + pibPerCapita2
                + (1.0f / densidadePopulacional2);

    /* ===== Exibição dos dados - Carta 1 ===== */
    printf("\nCarta 1:\n");
    printf("Estado: %s\n", estado1);
    printf("Código: %s\n", codigo1);
    printf("Nome da Cidade: %s\n", nomeCidade1);
    printf("População: %lu\n", populacao1);
    printf("Área: %.2f km²\n", area1);
    printf("PIB: %.2f bilhões de reais\n", pib1);
    printf("Número de Pontos Turísticos: %d\n", pontosTuristicos1);
    printf("Densidade Populacional: %.2f hab/km²\n", densidadePopulacional1);
    printf("PIB per Capita: %.2f reais\n", pibPerCapita1);
    printf("Super Poder: %.2f\n", superPoder1);

    /* ===== Exibição dos dados - Carta 2 ===== */
    printf("\nCarta 2:\n");
    printf("Estado: %s\n", estado2);
    printf("Código: %s\n", codigo2);
    printf("Nome da Cidade: %s\n", nomeCidade2);
    printf("População: %lu\n", populacao2);
    printf("Área: %.2f km²\n", area2);
    printf("PIB: %.2f bilhões de reais\n", pib2);
    printf("Número de Pontos Turísticos: %d\n", pontosTuristicos2);
    printf("Densidade Populacional: %.2f hab/km²\n", densidadePopulacional2);
    printf("PIB per Capita: %.2f reais\n", pibPerCapita2);
    printf("Super Poder: %.2f\n", superPoder2);

    /* ===== Comparações ===== */
    /*
     * Para todos os atributos (exceto densidade): maior valor vence → Carta 1 vence se (attr1 > attr2).
     * Para densidade populacional: menor valor vence → Carta 1 vence se (dens1 < dens2).
     *
     * O operador relacional em C retorna 1 (verdadeiro) ou 0 (falso).
     * Usamos esse valor diretamente para decidir a mensagem exibida.
     *
     * Sem if/else: a impressão condicional é feita via operador ternário (?:),
     * que não é estrutura de decisão mas sim operador de expressão — permitido.
     */
    int vencePopulacao        = (populacao1 > populacao2);
    int venceArea             = (area1 > area2);
    int vencePib              = (pib1 > pib2);
    int vencePontos           = (pontosTuristicos1 > pontosTuristicos2);
    int venceDensidade        = (densidadePopulacional1 < densidadePopulacional2); /* menor vence */
    int vencePibPerCapita     = (pibPerCapita1 > pibPerCapita2);
    int venceSuperPoder       = (superPoder1 > superPoder2);

    printf("\nComparação de Cartas:\n");

    printf("População: %s (%d)\n",
           vencePopulacao    ? "Carta 1 venceu" : "Carta 2 venceu", vencePopulacao);

    printf("Área: %s (%d)\n",
           venceArea         ? "Carta 1 venceu" : "Carta 2 venceu", venceArea);

    printf("PIB: %s (%d)\n",
           vencePib          ? "Carta 1 venceu" : "Carta 2 venceu", vencePib);

    printf("Pontos Turísticos: %s (%d)\n",
           vencePontos       ? "Carta 1 venceu" : "Carta 2 venceu", vencePontos);

    printf("Densidade Populacional: %s (%d)\n",
           venceDensidade    ? "Carta 1 venceu" : "Carta 2 venceu", venceDensidade);

    printf("PIB per Capita: %s (%d)\n",
           vencePibPerCapita ? "Carta 1 venceu" : "Carta 2 venceu", vencePibPerCapita);

    printf("Super Poder: %s (%d)\n",
           venceSuperPoder   ? "Carta 1 venceu" : "Carta 2 venceu", venceSuperPoder);

    return 0;
}
