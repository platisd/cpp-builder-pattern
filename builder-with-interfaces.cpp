#include <memory>
#include <string>
#include <vector>

namespace
{
class Menu
{
public:
    virtual ~Menu()                      = default;
    virtual void show() const            = 0;
    virtual void select(int index) const = 0;
};

class Builder
{
public:
    virtual ~Builder()                             = default;
    virtual Builder& withTitle(std::string title)  = 0;
    virtual Builder& withBorder(int pixels)        = 0;
    virtual Builder& addOption(std::string option) = 0;
    virtual Builder& horizontal()                  = 0;
    virtual Builder& vertical()                    = 0;
    virtual std::unique_ptr<Menu> build()          = 0;
};

class ProductionMenu : public Menu
{
public:
    class ProductionBuilder : public Builder
    {
    public:
        ProductionBuilder(std::string id)
            : mMenu{new ProductionMenu{id}}
        {
        }

        Builder& withTitle(std::string title)
        {
            mMenu->mTitle = title;
            return *this;
        }
        Builder& withBorder(int pixels)
        {
            mMenu->mBorder = pixels;
            return *this;
        }
        Builder& addOption(std::string o)
        {
            mMenu->mOpts.push_back(o);
            return *this;
        }
        Builder& horizontal()
        {
            mMenu->mHorizontal = true;
            return *this;
        }
        Builder& vertical()
        {
            mMenu->mHorizontal = false;
            return *this;
        }

        std::unique_ptr<Menu> build()
        {
            return std::move(mMenu);
        }

    private:
        std::unique_ptr<ProductionMenu> mMenu{};
    };

    void show() const {}
    void select(int /* index */) const {}

private:
    std::string mId{};
    std::string mTitle{};
    std::vector<std::string> mOpts{};
    bool mHorizontal{false};
    int mBorder{0};

    ProductionMenu(std::string id)
        : mId{id}
    {
    }
};
} // namespace

int main()
{
    const auto menu = ProductionMenu::ProductionBuilder{"main"}
                          .withTitle("Main Menu")
                          .withBorder(1)
                          .addOption("Option 1")
                          .addOption("Option 2")
                          .horizontal()
                          .build();
    menu->show();
    menu->select(1);

    return 0;
}
