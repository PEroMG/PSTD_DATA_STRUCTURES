<h1>
    <font dir="auto" style="vertical-align: inherit;">
        <font dir="auto" style="vertical-align: inherit;">Vis&atilde;o geral</font>
    </font>
</h1>
<p>
    <font dir="auto" style="vertical-align: inherit;">
        <font dir="auto" style="vertical-align: inherit;">&nbsp; &nbsp; Essa biblioteca possui diferentes estruturas de dados e fun&ccedil;&otilde;es de suporte.&nbsp;</font>
    </font>
</p>
<p><br></p>
<p>
    <font dir="auto" style="vertical-align: inherit;">
        <font dir="auto" style="vertical-align: inherit;">Atualmente se possui as seguintes estruturas de dados</font>
    </font>
</p>
<p>
    <font dir="auto" style="vertical-align: inherit;">
        <font dir="auto" style="vertical-align: inherit;">&nbsp;- PSTD::smart_array Um array din&acirc;mico com todas as funcionalidades de std::vector.</font>
    </font>
</p>
<p>
    <font dir="auto" style="vertical-align: inherit;">
        <font dir="auto" style="vertical-align: inherit;">&nbsp;- PSTD::array Um array de tamanho fixo, que serve para facilitar o uso de fun&ccedil;&otilde;es.</font>
    </font>
</p>
<p>
    <font dir="auto" style="vertical-align: inherit;">
        <font dir="auto" style="vertical-align: inherit;">&nbsp;- PSTD::lifetime Um tipo que substitui qualquer outro tipo, gerando sa&iacute;das de console quando qualquer construtor &eacute; chamado.</font>
    </font>
</p>
<p>
    <font dir="auto" style="vertical-align: inherit;">
        <font dir="auto" style="vertical-align: inherit;">&nbsp;- PSTD::PyRange Um cont&ecirc;iner falso. Feito &uacute;nica e exclusivamente para permitir declara&ccedil;&otilde;es de loop for no estilo de python</font>
    </font>
</p>
<p>
    <font dir="auto" style="vertical-align: inherit;">
        <font dir="auto" style="vertical-align: inherit;">&nbsp; &nbsp; ex: for(auto&amp; value : PSTD::PyRange(10)){ c&oacute;digo }</font>
    </font>
</p>
<p>
    <font dir="auto" style="vertical-align: inherit;">
        <font dir="auto" style="vertical-align: inherit;">&nbsp;- PSTD::iterate Um cont&ecirc;iner falso. Feito com o objetivo de deixar mais est&eacute;tico o uso de for loop com interadores, nos casos em que o loop n&atilde;o come&ccedil;a em come&ccedil;ar.</font>
    </font>
</p>
<p>
    <font dir="auto" style="vertical-align: inherit;">
        <font dir="auto" style="vertical-align: inherit;">&nbsp; &nbsp; ex: for(auto&amp; value : PSTD::iterate(container, 1, 5)){ c&oacute;digo }</font>
    </font>
</p>
<p><br></p>
<p>
    <font dir="auto" style="vertical-align: inherit;">
        <font dir="auto" style="vertical-align: inherit;">Fun&ccedil;&otilde;es de suporte</font>
    </font>
</p>
<p>
    <font dir="auto" style="vertical-align: inherit;">
        <font dir="auto" style="vertical-align: inherit;">&nbsp;- PSTD::iota uma vers&atilde;o de std::iota, com suporte para n&uacute;meros n&atilde;o inteiros e controle de incremento.</font>
    </font>
</p>
<p>
    <font dir="auto" style="vertical-align: inherit;">
        <font dir="auto" style="vertical-align: inherit;">&nbsp; &nbsp; Biblioteca padr&atilde;o: std::iota(container.begin(),container.end(),0); PSTD::data_estruturas: PSTD::iota(cont&ecirc;iner, 0); ou PSTD::iota(container.begin(),container.end(), 0);</font>
    </font>
</p>
<p>
    <font dir="auto" style="vertical-align: inherit;">
        <font dir="auto" style="vertical-align: inherit;">&nbsp;- PSTD::arrange Fun&ccedil;&atilde;o inspirada em Arrange da biblioteca nunpy, gerando um smart_array.</font>
    </font>
</p>
<p>
    <font dir="auto" style="vertical-align: inherit;">
        <font dir="auto" style="vertical-align: inherit;">&nbsp;- PSTD::linspace Fun&ccedil;&atilde;o inspirada em linspace do matlab, gerando um smart_array ou array.</font>
    </font>
</p>
